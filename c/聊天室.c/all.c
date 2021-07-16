#include "chatroom.h"
MYSQL mysql; //大bug注意多用户之间信息相混
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
char s[200];
void *body(void *arg);
void mysql_in_del(char *buf);
void mysql_select(char *buf, pack *recv_pack, int t);
void mysql_con();
int mysql_closet();
void registered(pack *recv_pack);
void sign(pack *recv_pack);
void find_words(pack *recv_pack);
void send_file();
void my_err(char *err_string, int line)
{
    fprintf(stderr, "line %d  ", line);
    perror(err_string);
    exit(1);
}
void send_t(pack *s, int sock_fd)
{
    if (send(sock_fd, s, sizeof(pack), 0) < 0)
        my_err("send", __LINE__);
}
void recv_t(pack *s, int sock_fd)
{
    if (recv(sock_fd, s, sizeof(pack), 0) < 0)
        my_err("recv", __LINE__);
}
void *body(void *arg)
{
    pthread_mutex_lock(&lock);
    pack *packs = ((pack *)arg);
    pack *recv_pack = (pack *)malloc(sizeof(pack));
    memcpy((void *)recv_pack, (void *)packs, sizeof(pack));
    pthread_mutex_unlock(&lock);
    int pid = pthread_self();
    printf("文件描述符%d\n", recv_pack->send_id);
    switch (recv_pack->cho)
    {
    case 'a':
        sign(recv_pack); //登陆
        break;
    case 'b':
        registered(recv_pack); //注册
        break;
    case 'c':
        find_words(recv_pack);
        break;
    default:
        pthread_exit(&pid);
        break;
    }
    return NULL;
}
void mysql_in_del(char *buf) //修改数据库
{
    int flag;
    flag = mysql_query(&mysql, buf);
    if (flag)
    {
        printf("ERROR:%s\n", mysql_error(&mysql));
    }
}
void mysql_select(char *buf, pack *recv_pack, int t) //数据库查询
{
    int flag;
    MYSQL_RES *result;
    MYSQL_ROW row;
    MYSQL_FIELD *field;
    flag = mysql_query(&mysql, buf);
    if (flag)
    {
        mysql_error(&mysql);
    }
    result = mysql_store_result(&mysql);
    if (result)
    {
        // while ((field = mysql_fetch_field(result)) != 0)   查看表头
        // {
        //     printf("%-15s", field->name);
        // }
        // printf("\n");
        while ((row = mysql_fetch_row(result)) != 0)
        {
            for (unsigned int i = 0; i < mysql_num_fields(result); i++)
            {
                if (row[i])
                {
                    switch (t)
                    {
                    case 0: //注册
                        recv_pack->send_nums = atoi((char *)row[i]);
                        break;
                    case 1: //找回密码
                    {
                        strncpy(recv_pack->work, (char *)row[i], sizeof(row[i]));         //密码
                        recv_pack->id = atoi((char *)row[i + 1]);                         //问题号
                        strncpy(recv_pack->nums, (char *)row[i + 2], sizeof(row[i + 2])); //回答
                        mysql_free_result(result);
                        return;
                    }
                    case 2: //登陆
                    {
                        strncpy(recv_pack->work, right, sizeof(right)); //只要能找到数据，就正确
                        return;
                    }
                    default:
                        break;
                    }
                }
                else
                {
                    if (t == 1)
                        recv_pack->cho = 'n';
                }
            }
        }
    }
    mysql_free_result(result);
}
void mysql_con() //数据库初始化,连接
{
    unsigned int nums;
    MYSQL_RES *res = NULL;
    mysql_init(&mysql);
    // mysql_library_init(0, NULL, NULL);
    if (mysql_real_connect(&mysql, "127.0.0.1", "root", passwords, "chat", 0, NULL, 0) == NULL)
    {
        my_err("mysql_real_connect", __LINE__);
    }
    // mysql_set_character_set(&mysql, "utf8");
}
int mysql_closet()
{
    mysql_close(&mysql);
    mysql_library_end();
    printf("数据库关闭\n");
    return 0;
}
void registered(pack *recv_pack) //注册函数
{

    sprintf(s, "insert into user_all (username,password,question,answer)"
               "values(\"%s\",\"%s\",%d,\"%s\")",
            recv_pack->send_name, recv_pack->work, recv_pack->id, recv_pack->nums);
    mysql_in_del(s);
    sprintf(s, "select number from user_all where username=\'%s\' ", recv_pack->send_name);
    mysql_select(s, recv_pack, 0);
    printf("%d", recv_pack->send_nums);
    send_t(recv_pack, recv_pack->send_id);
    printf("注册成功\n");
    return;
}
void sign(pack *recv_pack) //登陆函数
{
    sprintf(s, "select * from user_all where number=%d and password=\'%s\'", recv_pack->send_nums, recv_pack->work);
    mysql_select(s, recv_pack, 2);
    send_t(recv_pack, recv_pack->send_id);
    if (strcmp(recv_pack->work, right) != 0)
    {
        return;
    }
    sprintf(s, "update user_all set status=1 where number=%d", recv_pack->send_nums); //将用户状态设置为上线
    int flag = mysql_query(&mysql, s);
    if (flag)
    {
        printf("ERROR:%s\n", mysql_error(&mysql));
        exit(1);
    }
    send_t(recv_pack, recv_pack->send_id);
    printf("用户登陆成功");
}
void find_words(pack *recv_pack) //找回密码
{
    sprintf(s, "select password,question,answer from user_all where number=%d", recv_pack->send_nums);
    mysql_select(s, recv_pack, 1);
    send_t(recv_pack, recv_pack->send_id);
}
int main()
{
    int lid, cid;
    int ep_fd;
    int n = 20;
    pack *packs = (pack *)malloc(sizeof(pack));
    struct sockaddr_in client_addr, server_addr;
    lid = socket(AF_INET, SOCK_STREAM, 0);
    if (lid < 0)
    {
        my_err("socket", __LINE__);
    }
    int opt_val = 1;
    if (setsockopt(lid, SOL_SOCKET, SO_REUSEADDR, (void *)&opt_val, sizeof(int)) < 0)
    {
        my_err("setsockopt", __LINE__);
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (bind(lid, (struct sockaddr *)&server_addr, sizeof(server_addr)))
    {
        my_err("bind", __LINE__);
    }
    if (listen(lid, 20) < 0)
    {
        my_err("listen", __LINE__);
    }
    ep_fd = epoll_create(n);
    struct epoll_event ep_id;
    struct epoll_event ep_ids[12];
    ep_id.data.fd = lid;
    ep_id.events = EPOLLIN;
    epoll_ctl(ep_fd, EPOLL_CTL_ADD, lid, &ep_id);
    int events = size + 2;
    pthread_t pid;
    int tsize, nfs;
    socklen_t client_len = sizeof(client_addr);
    mysql_con();
    while (1)
    {
        if ((nfs = epoll_wait(ep_fd, ep_ids, events, -1)) < 0)
        {
            if (nfs == -1)
            {
                if (errno != EINTR)
                    my_err("epoll_wait", __LINE__);
            }
        }
        for (int i = 0; i < nfs; i++)
        {
            if (ep_ids[i].data.fd == lid) //有新的客户端连接
            {
                if ((cid = accept(lid, (struct sockaddr *)&client_addr, &client_len)) < 0)
                {
                    my_err("accept", __LINE__);
                }
                printf("连接到新的客户端:%s\n", inet_ntoa(client_addr.sin_addr));
                ep_id.data.fd = cid;
                ep_id.events = EPOLLIN;
                epoll_ctl(ep_fd, EPOLL_CTL_ADD, cid, &ep_id);
            }
            else if (ep_ids[i].events & EPOLLIN) //读数据
            {
                pthread_mutex_lock(&lock);
                if ((tsize = recv(ep_ids[i].data.fd, packs, sizeof(pack), 0)) < 0)
                {
                    my_err("recv", __LINE__);
                }
                else if (tsize == 0) //对端客户端关闭
                {
                    close(ep_ids[i].data.fd);
                    epoll_ctl(ep_fd, EPOLL_CTL_DEL, ep_ids[i].data.fd, &ep_id);
                }
                else
                {
                    packs->send_id = ep_id.data.fd;
                    printf("文件描述符%d",packs->send_id);
                    if (pthread_create(&pid, NULL, body, ((void *)packs)))
                    {
                        my_err("thread_create", __LINE__);
                    }
                    pthread_detach(pid);
                }
            }
            pthread_mutex_unlock(&lock);
        }
    }
    mysql_closet();
    return 0;
}
