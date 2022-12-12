#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <string.h>

#define MAX_ROUTE_ENTRY 100
#define MAX_PACKET_SIZE 1024
#define SIZE_ETHERNET 14


// 定义路由表的数据结构
struct RouteTable
{
    int size;              // 路由表的大小
    uint32_t network_addr; // 网络地址
    uint32_t netmask;      // 子网掩码
    uint32_t next_hop;     // 下一跳地址
    uint32_t metric;       // 路由距离
};

// 定义RIP协议报文的数据结构
struct rip
{
    uint8_t command;      // 命令类型
    uint8_t version;      // 协议版本号
    uint16_t num_entries; // 路由条目数量
    struct rip_entry
    {
        uint16_t family;       // 地址族类型
        uint16_t tag;          // 路由标签
        uint32_t network_addr; // 网络地址
        uint32_t netmask;      // 子网掩码
        uint32_t next_hop;     // 下一跳地址
        uint32_t metric;       // 路由距离
    } entries[];               // 路由条目数组
};

typedef struct
{
    unsigned int destination; //目的地
    unsigned int netmask; //网络掩码
    unsigned int gateway;//
    unsigned int interface;
} RouteEntry;

typedef struct
{
    unsigned int version : 4;
    unsigned int ihl : 4;
    unsigned int tos;
    unsigned int tot_len;
    unsigned int id;
    unsigned int frag_off;
    unsigned int ttl;
    unsigned int protocol;
    unsigned int check;
    unsigned int saddr;
    unsigned int daddr;
} IPHeader;


// 初始化路由表
void init_route_table(struct RouteTable *table)
{
    table->size = 0;
}

// 插入路由条目
int insert_route_entry(struct RouteTable *table, uint32_t network_addr, uint32_t netmask, uint32_t next_hop, uint32_t metric)
{
    // 判断路由表是否已满
    if (table->size == 255)
        return 0;

    // 将路由条目插入到路由表的末尾
    table->entries[table->size].network_addr = network_addr;
    table->entries[table->size].netmask = netmask;
    table->entries[table->size].next_hop = next_hop;
    table->entries[table->size].metric = metric;
    table->size++;

    return 1;
}

// 回调函数，用于处理每一个捕获到的数据包
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    // 定义各层协议头部的指针
    const struct ether_header *ether;
    const struct ip *ip;
    const struct udphdr *udp;
    const struct rip *rip;
    // 定义路由表的指针
    struct RouteTable *table;

    // 获取各层协议头部的指针
    ether = (struct ether_header *)(packet);
    ip = (struct ip *)(packet + SIZE_ETHERNET);
    udp = (struct udphdr *)(packet + SIZE_ETHERNET + sizeof(struct ip));
    rip = (struct rip *)(packet + SIZE_ETHERNET + sizeof(struct ip) + sizeof(struct udphdr));

    // 获取路由表的指针
    table = (struct RouteTable *)args;

    // 检查数据包是否是RIP协议报文
    if (ip->ip_p == IPPROTO_UDP && udp->source == htons(520))
    {
        // 解析RIP协议报文，更新路由表
        int i;
        for (i = 0; i < rip->num_entries; i++)
        {
            // 只处理IPv4地址族的路由条目
            if (rip->entries[i].family == htons(AF_INET))
            {
                // 获取路由条目的信息
                uint32_t network_addr = rip->entries[i].network_addr;
                uint32_t netmask = rip->entries[i].netmask;
                uint32_t next_hop = rip->entries[i].next_hop;
                uint32_t metric = rip->entries[i].metric;
                // 插入路由条目
                insert_route_entry(table, network_addr, netmask, next_hop, metric);
            }
        }
    }
}


// 读取IPv4分组
int read_packet(unsigned char *buffer, const char *filename)
{
    memset(buffer, 0, MAX_PACKET_SIZE);
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        return -1;
    }
    int ret = fread(buffer, 1, MAX_PACKET_SIZE, fp);
    fclose(fp);
    return ret;
}

// 写入IPv4分组
int write_packet(const unsigned char *buffer, int size, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        return -1;
    }
    int ret = fwrite(buffer, 1, size, fp);
    fclose(fp);
    return ret;
}

// 读取路由表
int read_route_table(RouteEntry *entries, const char *filename)
{
    memset(entries, 0, sizeof(RouteEntry) * MAX_ROUTE_ENTRY);
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        return -1;
    }
    int count = 0;
    while (count < MAX_ROUTE_ENTRY && fscanf(fp, "%u%u%u%u", &entries[count].destination, &entries[count].netmask, &entries[count].gateway, &entries[count].interface) == 4)
    {
        count++;
    }
    fclose(fp);
    return count;
}

// 写入路由表
int write_route_table(const RouteEntry *entries, int count, const char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        return -1;
    }
    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%u %u %u %u\n", entries[i].destination, entries[i].netmask, entries[i].gateway, entries[i].interface);
    }
    fclose(fp);
    return 0;
}

// 查找路由表
int find_route_entry(const RouteEntry *entries, int count, unsigned int destination)
{
    for (int i = 0; i < count; i++)
    {
        if ((entries[i].destination & entries[i].netmask) == (destination & entries[i].netmask))
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, char *argv[])
{
    // 定义pcap文件句柄、路由表和错误缓冲区
    pcap_t *handle;
    struct RouteTable table;
    char errbuf[PCAP_ERRBUF_SIZE];
    // 检查命令行参数
    if (argc != 2)
    {
        printf("Usage: %s <pcap file>\n", argv[0]);
        return -1;
    }

    // 打开pcap文件
    handle = pcap_open_offline(argv[1], errbuf);
    if (handle == NULL)
    {
        fprintf(stderr, "Couldn't open pcap file %s: %s\n", argv[1], errbuf);
        return -1;
    }

    // 初始化路由表
    init_route_table(&table);

    // 循环处理pcap文件中的每一个数据包
    pcap_loop(handle, 0, packet_handler, (u_char *)&table);

    // 关闭pcap文件
    pcap_close(handle);

    
// 读取IPv4分组
unsigned char buffer[MAX_PACKET_SIZE];
int size = read_packet(buffer, "fenzu.bin");
if (size <= 0) {
printf("读取IPv4分组失败\n");
return -1;
}

// 解析IPv4头部
IPHeader* ip = (IPHeader*)buffer;

// 更新TTL字段和校验和字段
ip->ttl--;
ip->check = 0;

// 读取路由表
RouteEntry entries[MAX_ROUTE_ENTRY];
int count = read_route_table(entries, "luyoubiao.txt");
if (count <= 0) {
printf("读取路由表失败\n");
return -1;
}

// 查找路由表
int index = find_route_entry(entries, count, ip->daddr);
if (index < 0) {
printf("未找到匹配的路由表项\n");
return -1;
}

// 转发IPv4分组
if (write_packet(buffer, size, "fenzu_out.bin") != size) {
printf("写入IPv4分组失败\n");
return -1;
}

// 打印转发日志
printf("成功转发IPv4分组：源地址=%u，目的地址=%u，网关=%u，接口=%u\n", ip->saddr, ip->daddr, entries[index].gateway, entries[index].interface);


    return 0;
}
