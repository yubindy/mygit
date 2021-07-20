#include "chatroom.h"
pack *recv_pack;
pack *send_pack;
pthnode *pthead;
int sock_fd;
int tiao = 0;
pthread_mutex_t get = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t forget = PTHREAD_COND_INITIALIZER;
void cli_find();
int cli_sign();
void cli_regist();
void cli_chuli();
void *recvs();
void cli_addfriend();
void cli_delfriend();
void cli_selfriend();
void cli_friendchat();
void next_jiemain();
void cli_message();
void cli_delfriend();
void cli_chatfriend();
void cli_creategroup();
void cli_delgroup();
void cli_selegroup();
void cli_groupchat();
void cli_filesned();
void *recvs() //一直收数据包
{
    sleep(1);
    int t;
    while (1)
    {
        pthread_mutex_lock(&get);
        while(tiao <= 0)
        {
            pthread_cond_wait(&forget, &get);
        }
        tiao = 0;
        recv_t(recv_pack, sock_fd);
        switch (recv_pack->cho)
        {
        case 'd':
        {
            printf("%s\n", recv_pack->work);
            break;
        }
        case 'e':
        {
            printf("%s\n", recv_pack->work);
            break;
        }
        case 'f': //显示所有好友
        {
            printf("你一共有%s个好友\n", recv_pack->work);
            printf("  0:下线 1：在线\n");
            t = atoi(recv_pack->work);
            for (int i = 0; i < t; i++)
            {
                if (recv(recv_pack->send_id, pthead, sizeof(pthnode), 0) < 0)
                    my_err("recv", __LINE__);
                printf("%s  %d\n", pthead->work, pthead->status);
            }
            printf("%s  %d", recv_pack->work, recv_pack->status);
            break;
        }
        case 'g': //私聊
        {
            printf("%s:%s", recv_pack->send_name, recv_pack->work);
            break;
        }
        case 'j':
        {
            printf("你一共有%s条消息\n", recv_pack->work);
            printf("快来处理一下吧,你的消息\n");
            t = recv_pack->id;
            pack *retpack = (pack *)malloc(sizeof(pack)); //返回包
            for (int i = 0; i < t; i++)
            {
                recv(sock_fd, (void *)pthead, sizeof(pthnode), 0);
                switch (pthead->status)
                {
                case 1:
                {
                    printf("%s想添加你为好友(yes.同意 no.拒绝)\n", recv_pack->send_name);
                    scanf("%s", retpack->work);
                    strcpy(retpack->send_name, recv_pack->recv_name);
                    strcpy(retpack->recv_name, recv_pack->send_name);
                    send_t(retpack, sock_fd);
                    break;
                }
                case 2:
                {
                    printf("%s已经删除你\n", recv_pack->send_name);
                    break;
                }
                case 3:
                {
                    printf("%s发出申请加入群聊%s(yes.同意 no.拒绝)\n", recv_pack->send_name, recv_pack->recv_name);
                }
                case 4:
                {
                    printf("%s已经同意你的好友请求\n", recv_pack->send_name);
                }
                case 6:
                {
                    printf("你已经成功加入群聊%s\n",
                           recv_pack->recv_name);
                }
                default:
                    break;
                }
            }
        }
        }
        pthread_mutex_unlock(&get);
    }
}
void cli_selfriend()
{
    send_t(recv_pack, sock_fd);
    recv(sock_fd, (void *)pthead, sizeof(pthnode) * (size + 1), 0);
    pthnode *q = pthead->next;
    int t = atoi(pthead->work);
    printf("你一共有%d个好友", t);
    for (int i = 0; i < t; i++)
    {
        printf("%s\n", q->work);
        q = q->next;
    }
}
void cli_addfriend()
{
    printf("请输入姓名搜索\n");
    scanf("%s", send_pack->recv_name);
    send_t(send_pack, sock_fd);
}
void cli_delfriend()
{
    printf("请输入需要删除的好友姓名：");
    scanf("%s", send_pack->recv_name);
    send_t(send_pack, sock_fd);
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
void cli_delu()
{
    int pand = 0;
    while (1)
    {
        printf("---欢迎来到简单的聊天室---\n");
        printf("%5s", "a.登陆\n");
        printf("%5s", "b.注册\n");
        printf("%5s", "c.找回密码\n");
        printf("%5s", "q.退出\n");
        printf("----------------------------\n");
        scanf("%c", &send_pack->cho);
        switch (send_pack->cho)
        {
        case 'a':
            pand = cli_sign();
            if (pand != 0)
            {
                next_jiemain();
                return;
            }
            break;
        case 'b':
            cli_regist();
            break;
        case 'c':
            cli_find();
            break;
        case 'q':
        {
            close(sock_fd);
            exit(0);
        }
        default:
            printf("无效输入，请重试\n");
        }
        scanf("%c", &send_pack->cho);
    }
}
void next_jiemain()
{
    pthread_t pid;

    strcpy(send_pack->send_name, recv_pack->send_name);
    pthread_create(&pid, NULL, recvs, NULL);
    while (1)
    {
        pthread_mutex_lock(&get);
        tiao = 1;
        printf("---欢迎来到简单的聊天室---\n");
        printf("%5s", "d.加好友\n");
        printf("%5s", "e.删除好友\n");
        printf("%5s", "f.显示全部好友和状态\n");
        printf("%5s", "g.私聊\n");
        printf("%5s", "h.创建群\n");
        printf("%5s", "i.退群\n");
        printf("%5s", "j.显示所有群\n");
        printf("%5s", "k.群聊\n");
        printf("%5s", "l.传输文件\n");
        printf("%5s", "j.消息中心\n");
        printf("%5s", "q.退出\n");
        printf("----------------------------\n");
        scanf("%c%c", &send_pack->cho, &send_pack->cho);
        switch (send_pack->cho)
        {
        case 'd':
            cli_addfriend();
            break;
        case 'e':
            cli_delfriend();
            break;
        case 'f':
            cli_selfriend();
            break;
        case 'g':
            cli_chatfriend();
            break;
        // case 'h':
        //     cli_addfriend(sock_fd);
        // case 'i':
        //     cli_addfriend(sock_fd);
        // case 'j':
        //     cli_addfriend(sock_fd);
        // case 'l':
        //     cli_addfriend(sock_fd);
        // case 'j':
        //     cli_addfriend(sock_fd);
        case 'q':
        {
            close(sock_fd);
            exit(0);
        }
        case '\n':
            break;
        default:
            printf("无效输入，请重试\n");
        }
        pthread_mutex_unlock(&get);
        if (tiao > 0)
        {
            pthread_cond_signal(&forget);
        }
        sleep(1);
    }
}
int cli_sign()
{
    printf("账号:");
    scanf("%d", &send_pack->send_nums);
    mima(send_pack->work);
    send_t(send_pack, sock_fd);
    recv_t(recv_pack, sock_fd);
    if (strncmp(recv_pack->work, right, sizeof(right)) != 0)
    {
        printf("\n密码错误，请重新登陆\n");
        return 0;
    }
    else
    {
        printf("\n登陆成功\n");
        recv_pack->status = 1;
        return 1;
    }
}
void cli_regist()
{
    printf("请输入昵称：");
    scanf("%s", send_pack->send_name);
    mima(send_pack->work);
    while (1)
    {
        printf("\n请对于以下密保问题作出选择并输入答案\n");
        printf("1.你的大学是：\n");
        printf("2.你的父亲是：\n");
        printf("3.你的爱好是：\n");
        scanf("%d", &send_pack->id); //存贮选项
        if (send_pack->id >= 1 && send_pack->id <= 3)
            break;
        else
            printf("无效输入，请重新输入");
    }
    scanf("%s", send_pack->nums);
    send_t(send_pack, sock_fd);
    recv_t(recv_pack, sock_fd);
    printf("账号：%d 昵称：%s\n", recv_pack->send_nums, recv_pack->send_name);
    printf("注册成功\n");
}
void cli_find()
{
    char t[10];
    printf("请输入账号:");
    scanf("%d", &send_pack->send_nums);
    send_t(send_pack, sock_fd);
    recv_t(recv_pack, sock_fd);
    if (recv_pack->cho == 'c')
    {
        switch (recv_pack->id)
        {
        case 1:
            printf("你的大学是:");
            break;
        case 2:
            printf("你的父亲是:");
            break;
        case 3:
            printf("你的爱好是:");
            break;
        }
        scanf("%s", t);
        if (strcmp(t, recv_pack->nums) == 0)
            printf("该账号密码为:%s\n", recv_pack->work);
        else
            printf("回答错误，请重试\n");
    }
    else
        printf("账号错误，请重新输入\n");
}
void cli_message()
{
    printf("---------消息中心----------\n");
    send_t(recv_pack, recv_pack->send_id);
}
void cli_chatfriend()
{
    printf("请输入需要私聊的用户姓名：");
    scanf("%s", send_pack->recv_name);
    send_t(send_pack, send_pack->send_id);
    printf("聊天中..........(输入exit,退出聊天)\n");
}
int main()
{
    struct sockaddr_in cid;
    recv_pack = (pack *)malloc(sizeof(pack));
    send_pack = (pack *)malloc(sizeof(pack));
    pthead = (pthnode *)malloc(sizeof(pthnode));
    pthnode *pt, *qt;
    qt = pthead;
    for (int i = 0; i <= size; i++)
    {
        pt = (pthnode *)malloc(sizeof(pthnode));
        pt = qt->next;
    }
    char nums[20];
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0)
    {
        my_err("socket", __LINE__);
    }
    int opt_val = 1;
    if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, (void *)&opt_val, sizeof(int)) < 0)
    {
        my_err("setsockopt", __LINE__);
    }
    memset(&cid, 0, sizeof(cid));
    cid.sin_port = htons(port);
    cid.sin_family = AF_INET;
    printf("请输入服务器地址:");
    fgets(nums, 20, stdin);
    nums[strlen(nums) - 1] = '\0';
    if (inet_aton(nums, &cid.sin_addr) < 0)
    {
        printf("无效的服务器地址:%s", nums);
        exit(1);
    }
    if (connect(sock_fd, (struct sockaddr *)&cid, sizeof(cid)) < 0)
    {
        my_err("connect", __LINE__);
    }
    cli_delu();
}