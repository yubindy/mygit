#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <string.h>

typedef struct RouteTable
{
    uint32_t dest_ip;  // 目的IP地址
    uint32_t next_hop; // 下一跳IP地址
    uint32_t metric;   // 路径长度（跳数）
} RouteTable;

void update_route_table(const char *pcap_file)
{
    // 打开pcap文件
    pcap_t *handle = pcap_open_offline(pcap_file, NULL);
    if (handle == NULL)
    {
        fprintf(stderr, "Failed to open pcap file: %s\n", pcap_file);
        return;
    }

    // 定义用于存储数据分组的缓冲区
    const int BUF_SIZE = 65535;
    uint8_t packet[BUF_SIZE];

    // 定义用于存储pcap文件头信息的结构体
    struct pcap_pkthdr *header;

    // 定义路由表
    RouteTable route_table[1024];
    int num_entries = 0;

    // 循环读取pcap文件中的数据分组
    while (pcap_next_ex(handle, &header, (const u_char **)&packet) == 1)
    { // 获取数据分组的长度
        int packet_len = header->len;
        // 解析数据分组，获取源IP地址、目的IP地址和传输层协议类型
        uint32_t src_ip = 0;
        uint32_t dst_ip = 0;
        uint8_t protocol = 0;
        parse_packet(packet, packet_len, &src_ip, &dst_ip, &protocol);

        // 如果数据分组使用的是RIP协议，则更新路由表
        if (protocol == IPPROTO_RIP)
        {
            // 解析RIP路由更新报文，获取路由信息
            int num_routes = 0;
            RouteTable routes[1024];
            parse_rip_packet(packet, packet_len, &num_routes, routes);

            // 遍历路由信息，更新路由表
            for (int i = 0; i < num_routes; i++)
            {
                uint32_t dest_ip = routes[i].dest_ip;
                uint32_t next_hop = routes[i].next_hop;
                uint32_t metric = routes[i].metric;

                // 如果路由表中已经存在相同的路由信息，则更新路由表
                int found = 0;
                for (int j = 0; j < num_entries; j++)
                {
                    if (route_table[j].dest_ip == dest_ip &&
                        route_table[j].next_hop == next_hop)
                    {
                        route_table[j].metric = metric;
                        found = 1;
                        break;
                    }
                }

                // 如果路由表中不存在相同的路由信息，则添加新的路由信息
                if (!found)
                {
                    route_table[num_entries].dest_ip = dest_ip;
                    route_table[num_entries].next_hop = next_hop;
                    route_table[num_entries].metric = metric;
                    num_entries++;
                }
            }
        }
    }

    // 关闭pcap文件
    pcap_close(handle);
}
//在上面的代码中，我们首先打开了pcap文件，然后循环读取pcap文件中的数据分组。对于每个数据分组，我们首先解析出源IP地址、
//目的IP地址和传输层协议类型，然后判断该数据分组是否使用了RIP协议。如果使用了RIP协议，我们就解析出该数据分组中的路由信息，并更新路由表。
//上面的代码中使用了两个辅助函数：parse_packet 和 parse_rip_packet。这两个函数的实现可以参考下面的代码：

// 解析数据分组，获取源IP地址、目的IP地址和传输层协议类型
void parse_packet(const uint8_t *packet, int packet_len, uint32_t *src_ip,
                  uint32_t *dst_ip, uint8_t *protocol)
{
    // 解析IP数据报头部
    struct iphdr *ip_header = (struct iphdr *)packet;
    *src_ip = ip_header->saddr;
    *dst_ip = ip_header->daddr;
    *protocol = ip_header->protocol;
}

// 解析RIP路由更新报文，获取路由信息
void parse_rip_packet(const uint8_t *packet, int packet_len, int *num_routes,
                      RouteTable *routes)
{
    // 获取RIP数据报的起始位置
    uint8_t *rip_packet = packet + sizeof(struct iphdr);
    int rip_packet_len = packet_len - sizeof(struct iphdr);

    // 解析RIP数据报
    struct rip_packet *rip = (struct rip_packet *)rip_packet;

    // 获取RIP消息的类型
    uint8_t command = rip->command;

    // 如果RIP消息的类型是REQUEST，则返回
    if (command == RIP_REQUEST)
    {
        return;
    }

    // 如果RIP消息的类型是RESPONSE，则解析路由信息
    if (command == RIP_RESPONSE)
    {
        // 获取RIP消息中包含的路由信息数量
        *num_routes = (rip_packet_len - 4) / 20;

        // 遍历所有路由信息
        for (int i = 0; i < *num_routes; i++)
        {
            // 获取第i条路由信息的起始位置
            uint8_t *route = rip_packet + 4 + i * 20;

            // 解析第i条路由信息
            struct rip_route *rip_route = (struct rip_route *)route;
            routes[i].dest_ip = rip_route->addr;
            routes[i].next_hop = rip_route->nexthop;
            routes[i].metric = rip_route->metric;
        }
    }
}

// 在上面的代码中，我们首先解析了IP数据报头部，获取源IP地址、目的IP地址和传输层协议类型。
//然后，我们解析了RIP数据报，获取RIP消息的类型。如果RIP消息的类型是REQUEST，则直接返回；
//如果RIP消息的类型是RESPONSE，则解析RIP消息中包含的路由信息，并存储到给定的数组中。
//通过上面的代码，我们就可以实现从pcap文件中读取RIP协议路由更新报文并构建更新路由表的功能。

void build_route_table(const char *pcap_file)
{
    // 打开pcap文件
    pcap_t *handle = pcap_open_offline(pcap_file, NULL);
    if (handle == NULL)
    {
        fprintf(stderr, "Failed to open pcap file: %s\n", pcap_file);
        return;
    }

    // 定义用于存储数据分组的缓冲区
    const int BUF_SIZE = 65535;
    uint8_t packet[BUF_SIZE];

    // 定义用于存储pcap文件头信息的结构体
    struct pcap_pkthdr *header;

    // 定义路由表
    RouteTable route_table[1024];
    int num_entries = 0;

    // 循环读取pcap文件中的数据分组
    while (pcap_next_ex(handle, &header, (const u_char **)&packet) == 1)
    {
        // 获取数据分组的长度
        int packet_len = header->len;

        // 解析数据分组，获取源IP地址、目的IP地址和传输层协议类型
        uint32_t src_ip = 0;
        uint32_t dst_ip = 0;
        uint8_t protocol = 0;
        parse_packet(packet, packet_len, &src_ip, &dst_ip, &protocol);

        // 如果数据分组使用的是RIP协议，则构建路由表
        if (protocol == IPPROTO_RIP)
        {
            // 解析RIP路由更新报文，获取路由信息
            int num_routes = 0;
            RouteTable routes[1024];
            parse_rip_packet(packet, packet_len, &num_routes, routes);
            // 遍历路由信息，更新路由表
            for (int i = 0; i < num_routes; i++)
            {
                uint32_t dest_ip = routes[i].dest_ip;
                uint32_t next_hop = routes[i].next_hop;
                uint32_t metric = routes[i].metric;

                // 如果路由表中已经存在相同的路由信息，则更新路由表
                int found = 0;
                for (int j = 0; j < num_entries; j++)
                {
                    if (route_table[j].dest_ip == dest_ip &&
                        route_table[j].next_hop == next_hop)
                    {
                        route_table[j].metric = metric;
                        found = 1;
                        break;
                    }
                }

                // 如果路由表中不存在相同的路由信息，则添加新的路由信息
                if (!found)
                {
                    route_table[num_entries].dest_ip = dest_ip;
                    route_table[num_entries].next_hop = next_hop;
                    route_table[num_entries].metric = metric;
                    num_entries++;
                }
            }
        }
    }

    // 关闭pcap文件
    pcap_close(handle);
}

void process_packet(const uint8_t *packet, int packet_len,
                    const RouteTable *route_table, int num_entries)
{
    // 解析IP数据报头部
    struct iphdr *ip_header = (struct iphdr *)packet;

    // 获取数据报的目的IP地址
    uint32_t dst_ip = ip_header->daddr;

    // 查找路由表，获取下一跳地址
    uint32_t next_hop = 0;
    for (int i = 0; i < num_entries; i++)
    {
        if (route_table[i].dest_ip == dst_ip)
        {
            next_hop = route_table[i].next_hop;
            break;
        }
    }

    // 如果没有找到对应的下一跳地址，则直接返回
    if (next_hop == 0)
    {
        return;
    }

    // 更新TTL字段和校验和字段
    ip_header->ttl--;
    ip_header->check = 0;
    ip_header->check = checksum((uint8_t *)ip_header, sizeof(struct iphdr));

    // 将分组写入fenzu.txt
    write_packet_to_file(packet, packet_len, "fenzu.txt");
}
void write_route_table_to_file(const RouteTable *route_table, int num_entries,
                               const char *file_name)
{
    // 打开文件
    FILE *file = fopen(file_name, "w");
    if (file == NULL)
    {
        fprintf(stderr, "Failed to open file: %s\n", file_name);
        return;
    }

    // 写入路由表
    for (int i = 0; i < num_entries; i++)
    {
        uint32_t dest_ip = route_table[i].dest_ip;
        uint32_t next_hop = route_table[i].next_hop;
        uint32_t metric = route_table[i].metric;
        fprintf(file, "%u.%u.%u.%u %u.%u.%u.%u %u\n", dest_ip & 0xff,
                (dest_ip >> 8) & 0xff, (dest_ip >> 16) & 0xff,
                (dest_ip >> 24) & 0xff, next_hop & 0xff, (next_hop >> 8) & 0xff,
                (next_hop >> 16) & 0xff, (next_hop >> 24) & 0xff, metric);
    }

    // 关闭文件
    fclose(file);
}

int main()
{
    // 构建并更新路由表
    RouteTable route_table[1024];
    int num_entries = 0;
    build_route_table("pcap_file.pcap", &num_entries, route_table);

    // 收到IPV4分组后按照转发规则处理
    uint8_t packet[65535];
    int packet_len = read_packet_from_file("packet.txt", packet);
    process_packet(packet, packet_len, route_table, num_entries);

    // 将路由表写入luyoubiao.txt文件
    write_route_table_to_file(route_table, num_entries, "luyoubiao.txt");

    return 0;
}
