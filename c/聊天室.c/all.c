#include "chatroom.h"
MYSQL mysql;
pthnode *pthead; //私聊具体实现
node *head = NULL;
node *end = NULL;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lockwords = PTHREAD_MUTEX_INITIALIZER;
void *body(void *arg);
void mysql_in_del(char *buf);
int mysql_select(char *buf, pack *recv_pack, int t);
void mysql_con();
int mysql_closet();
void registered(pack *recv_pack);
void sign(pack *recv_pack);
void find_words(pack *recv_pack);
void send_file();
int find_status(char *name);
void add_friend(pack *recv_pack);
void del_friend(pack *recv_pack);
void select_friend(pack *recv_pack);
void chat_friend(pack *recv_pack);
void message(pack *recv_pack);
int find_status(char *name) //查找用户在线否
{
    node *cname = head->next;
    while (cname->next != NULL)
    {
        if (strcmp(cname->t, name) == 0)
        {
            return 1;
        }
        cname=cname->next;
    }
    return 0;
}
void chat_friend(pack *recv_pack) //私聊
{
    char s[200];
    int t = 0;
    sprintf(s, "select user,friend from friend where recv_name=\'%s\'and send_name=\'%s\'union "
               "select user,friend from friend where recv_name=\'%s\'and send_name=\'%s\'",
            recv_pack->recv_name, recv_pack->send_name, recv_pack->send_name, recv_pack->recv_name);
    if (t == mysql_select(s, recv_pack, 3)) //如果没有加好友
    {
        strcpy(recv_pack->work, "对不起，你暂时没有该好友");
        send_t(recv_pack, recv_pack->send_id);
        return;
    }
    sprintf(s, "insert into frienf_histroy (recv_name,send_name,words)" //加入好友历史
               "values(\'%s\',\'%s\',\'%s\')",
            recv_pack->recv_name, recv_pack->send_name, recv_pack->work);
    if (t == find_status(recv_pack->recv_name)) //如果对方不在线,加入消息表
    {
        sprintf(s, "insert into message(recv_name,send_name,id,words)" //id=7，好友未读消息
                   "values(\'%s\',\'%s\',7,\'%s\')",
                recv_pack->recv_name, recv_pack->send_name, recv_pack->work);
        strcpy(recv_pack->work, "对不起，该好友没有上线\n");
        send_t(recv_pack, recv_pack->send_id);
    }
}
void mysql_select_words(char *buf, pack *recv_pack, int t) //查询多条信息,写入链表
{
    int flag;
    MYSQL_RES *result;
    MYSQL_ROW row;
    MYSQL_FIELD *field;
    pthnode *s = pthead->next;
    flag = mysql_query(&mysql, buf);
    if (flag)
    {
        mysql_error(&mysql);
    }
    result = mysql_store_result(&mysql);
    if (result)
    {
        int number = mysql_num_rows(result);
        if (t == 0)
        {
            while ((row = mysql_fetch_row(result)) != 0)
            {
                for (unsigned int i = 0; i < mysql_num_fields(result); i++)
                {
                    if (row[i])
                    {
                        if (strcmp((char *)row[i], recv_pack->send_name) != 0)
                        {
                            strcpy(s->work, (void *)row[i]);
                            s->status = find_status(s->work);
                            s = s->next;
                        }
                    }
                }
            }
            sprintf(recv_pack->work, "%d", number);
        }
        else if (t == 1)
        {
            while ((row = mysql_fetch_row(result)) != 0)
            {
                for (unsigned int i = 0; i < mysql_num_fields(result); i++)
                {
                    if (row[i])
                    {
                        strcpy(s->work, (void *)row[i]);
                        s->status = atoi(row[i + 1]);
                        s = s->next;
                    }
                    break;
                }
            }
            sprintf(recv_pack->work, "%d", number);
        }
    }
    mysql_free_result(result);
}
void my_err(char *err_string, int line)
{
    fprintf(stderr, "line %d  ", line);
    perror(err_string);
    exit(1);
}
void send_t(pack *s, int fd)
{

    if (send(fd, s, sizeof(pack), 0) < 0)
        my_err("send", __LINE__);
}
void recv_t(pack *s, int fd)
{
    if (recv(fd, s, sizeof(pack), 0) < 0)
        my_err("recv", __LINE__);
}
void *body(void *arg)
{
    pack *packs = ((pack *)arg);
    pack *recv_pack = (pack *)malloc(sizeof(pack));
    memcpy((void *)recv_pack, (void *)packs, sizeof(pack));
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
    case 'd':
        add_friend(recv_pack);
        break;
    case 'e':
        del_friend(recv_pack);
        break;
    case 'f':
        select_friend(recv_pack);
        break;
    case 'j':
        message(recv_pack);
        break;
    default:
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
int mysql_select(char *buf, pack *recv_pack, int t) //数据库查询单条消息或判断存在
{
    int flag;
    MYSQL_RES *result;
    MYSQL_ROW row;
    MYSQL_FIELD *field;
    int number = 0;
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
        if (t == 4)
        {
            number = mysql_num_rows(result); //计算查询结果数量
            return number;
        }
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
                        return 0;
                    case 1: //找回密码
                    {
                        strncpy(recv_pack->work, (char *)row[i], sizeof(row[i]));         //密码
                        recv_pack->id = atoi((char *)row[i + 1]);                         //问题号
                        strncpy(recv_pack->nums, (char *)row[i + 2], sizeof(row[i + 2])); //回答
                        mysql_free_result(result);
                        return 0;
                    }
                    case 2: //登陆
                    {
                        strncpy(recv_pack->work, right, sizeof(right)); //只要能找到数据，就正确
                        strcpy(recv_pack->send_name, (void *)row[i]);
                        mysql_free_result(result);
                        return 0;
                    }
                    case 3:
                    {
                        //只要能找到数据，就正确
                        mysql_free_result(result);
                        return 1;
                    }
                    default:
                        break;
                    }
                }
            }
        }
    }
    mysql_free_result(result);
    return 0;
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
    char s[200];
    sprintf(s, "insert into user_all (username,password,question,answer)"
               "values(\'%s\',\'%s\',%d,\'%s\')",
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
    char s[200];
    sprintf(s, "select username from user_all where number=%d and password=\'%s\'", recv_pack->send_nums, recv_pack->work);
    mysql_select(s, recv_pack, 2);
    send_t(recv_pack, recv_pack->send_id);
    if (strcmp(recv_pack->work, right) != 0)
    {
        return;
    }
    recv_pack->status = 1;
    pthread_mutex_lock(&lock);
    node *p = (node *)malloc(sizeof(node));
    strcpy(p->t, recv_pack->send_name);
    p->id=recv_pack->send_id;
    end->next = p;
    pthread_mutex_unlock(&lock);
    send_t(recv_pack, recv_pack->send_id);
    printf("用户登陆成功");
}
void find_words(pack *recv_pack) //找回密码
{
    char s[200];
    sprintf(s, "select password,question,answer from user_all where number=%d", recv_pack->send_nums);
    mysql_select(s, recv_pack, 1);
    send_t(recv_pack, recv_pack->send_id);
}
void add_friend(pack *recv_pack) //加好友
{
    char s[200];
    int t = 0;
    sprintf(s, "select * from user_all where username=\'%s\'", recv_pack->recv_name);
    if (t == mysql_select(s, recv_pack, 3))
    {
        strcpy(recv_pack->work, "没有找到该用户"); //没有找到好友
    }
    else
    {
        strcpy(recv_pack->work, "申请已经发送请等待");
    }
    recv_pack->id = 1;
    send_t(recv_pack, recv_pack->send_id);
    sprintf(s, "insert into message(recv_name,send_name,id)values(\'%s\',\'%s\',%d)",
            recv_pack->recv_name, recv_pack->send_name, recv_pack->id); //将消息写进表中
    mysql_in_del(s);
}
void del_friend(pack *recv_pack)
{
    char s[200];
    int t = 0;
    sprintf(s, "select user,friend from friend where recv_name=\'%s\'and send_name=\'%s\'union "
               "select user,friend from friend where recv_name=\'%s\'and send_name=\'%s\'",
            recv_pack->recv_name, recv_pack->send_name, recv_pack->send_name, recv_pack->recv_name);
    if (t == mysql_select(s, recv_pack, 3))
    {
        strcpy(recv_pack->work, "你并不存在该好友"); //没有找到好友
        send_t(recv_pack, recv_pack->send_id);
        return;
    }
    else
    {
        strcpy(recv_pack->work, "你已经删除该好友");
        send_t(recv_pack, recv_pack->send_id);
    }
    sprintf(s, "delete from friend where recv_name=\'%s\'and send_name=\'%s\'", recv_pack->recv_name, recv_pack->send_name);
    mysql_in_del(s);
    sprintf(s, "delete from friend where recv_name=\'%s\'and send_name=\'%s\'", recv_pack->send_name, recv_pack->recv_name);
    mysql_in_del(s);
    recv_pack->id = 2;
    sprintf(s, "insert from message(recv_name,send_name,id,status)values(\'%s\',\'%s\',%d,2)",
            recv_pack->recv_name, recv_pack->send_name, recv_pack->id); //将消息写进表中
    mysql_in_del(s);
}
void select_friend(pack *recv_pack)
{
    char s[200];
    int all;
    pthnode *t = pthead->next;
    sprintf(s, "select recv_name,send_name from friend where recv_name=\'%s\'and send_name=\'%s\' "
               "union select recv_name,send_name from friend where recv_name=\'%s\'and send_name=\'%s\' ",
            recv_pack->send_name, recv_pack->recv_name, recv_pack->recv_name, recv_pack->send_name);
    pthread_mutex_lock(&lockwords);
    memset(pthead, 0, sizeof(pthnode) * (size + 1));
    mysql_select_words(s, recv_pack, 0);
    all = mysql_select(s, recv_pack, 4);
    recv_pack->id = all;
    send_t(recv_pack, recv_pack->send_id);
    for (int i = 0; i < all; i++)
    {
        if (send(recv_pack->send_id, t, sizeof(pthnode), 0) < 0)
        {
            my_err("send", __LINE__);
        }
        t = t->next;
    }
    pthread_mutex_unlock(&lockwords);
}
void message(pack *recv_pack) //消息中心
{
    char s[200];
    int number;
    int all;
    pthnode *t = pthead->next;
    sprintf(s, "select send_name,id from message where recv_name=\'%s\'and id>0", recv_pack->send_name);
    pthread_mutex_lock(&lockwords);
    mysql_select_words(s, recv_pack, 1);
    pthread_mutex_unlock(&lockwords);
    all = atoi(recv_pack->work);
    sprintf(s, "select send_name,id from message where recv_name=\'%s\'and id=1",
            recv_pack->send_name);
    number = mysql_select(s, recv_pack, 4);
    recv_pack->id = number; //好友请求数量
    send_t(recv_pack, recv_pack->send_id);
    while (all--) //处理all个请求
    {
        send(recv_pack->send_id, (void *)t, sizeof(pthnode), 0); //每次发送1个节点的数据
        if (t->status == 1)
        {
            recv_t(recv_pack, recv_pack->send_id);
            if (strcmp(recv_pack->work, "yes") == 0)
            {
                sprintf(s, "insert into friend(recv_name,send_name)" //加入好友
                           "values(\'%s\',\'%s\')",
                        recv_pack->send_name, recv_pack->recv_name);
                mysql_in_del(s);
                sprintf(s, "update message set id=4,send_name=\'%s\',recv_name=\'%s\'"
                           " where recv_name=\'%s\' and send_name=\'%s\'",
                        recv_pack->send_name, recv_pack->recv_name,
                        recv_pack->send_name, recv_pack->recv_name);
                mysql_in_del(s);
            }
        }
        else
        {
            sprintf(s, "update message set id=0 where recv_name=\'%s\' ", recv_pack->send_name);
            mysql_in_del(s); //信息传完后，将所有状态设置为0,已发送
        }
        t = t->next;
    }
}
int main()
{
    int lid, cid, ep_fd;
    signal(SIGPIPE, SIG_IGN);
    head = (node *)malloc(sizeof(node));
    end=head;
    pack *packs = (pack *)malloc(sizeof(pack));
    pthead = (pthnode *)malloc(sizeof(pthnode));
    pthnode *a,*b=pthead;
    for(int i=0;i<size;i++)
    {
        a=(pthnode*)malloc(sizeof(pthnode));
        b->next=a;
        b=b->next;
    }
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
    ep_fd = epoll_create(size);
    struct epoll_event ep_id;
    struct epoll_event ep_ids[size];
    ep_id.data.fd = lid;
    ep_id.events = EPOLLIN;
    epoll_ctl(ep_fd, EPOLL_CTL_ADD, lid, &ep_id);
    int events = size;
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
                printf("accept:%d\n", cid);
                ep_id.data.fd = cid;
                ep_id.events = EPOLLIN;
                epoll_ctl(ep_fd, EPOLL_CTL_ADD, cid, &ep_id);
            }
            else if (ep_ids[i].events & EPOLLIN) //读数据
            {
                if ((tsize = recv(ep_ids[i].data.fd, packs, sizeof(pack), 0)) < 0)
                {
                    my_err("recv", __LINE__);
                }
                else if (tsize == 0) //对端客户端关闭
                {
                    close(ep_ids[i].data.fd);
                    node *t=head;
                    node *o;
                    while(t->next!=NULL)
                    {  
                        if(t->next->id==ep_ids[i].data.fd)
                        { 
                          if(t->next==end)
                          {
                              end=t;
                          }
                          o=t->next;
                          t->next=t->next->next;
                          free(o);
                          break;
                        }
                        t=t->next;
                    }
                    epoll_ctl(ep_fd, EPOLL_CTL_DEL, ep_ids[i].data.fd, &ep_id);
                }
                else
                {
                    packs->send_id = ep_ids[i].data.fd;
                    if (pthread_create(&pid, NULL, body, (void *)packs))
                    {
                        my_err("thread_create", __LINE__);
                    }
                    pthread_detach(pid);
                }
            }
        }
    }
    mysql_closet();
    return 0;
}
