#include "chatroom.h"
pack *recv_pack;
pack *send_pack;   //群聊有问题看看
pthnode *pthead;
groupnode *grohead;
int sock_fd;
int tiao = 0;
int mes = 0;
int cf = 0;
int first = 0;
int flag = 1;
int groupflag = 1;
// pthread_mutex_t resend = PTHREAD_MUTEX_INITIALIZER;
// pthread_cond_t toresend = PTHREAD_COND_INITIALIZER;
pthread_mutex_t get = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t groups = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t forget = PTHREAD_COND_INITIALIZER;
pthread_cond_t toget = PTHREAD_COND_INITIALIZER;
void cli_find();
int cli_sign();
void cli_regist();
void cli_chuli();
void recvs();
void *nextst();
void chatjuti();
void cli_addfriend();
void cli_delfriend();
void cli_selfriend();
void cli_friendchat();
void next_jiemain();
void cli_message();
void cli_delfriend();
void cli_chatfriend();
void *grouprecv();
void cli_creategroup();
void cli_delgroup();
void cli_selegroup();
void cli_groupchat();
void cli_filesned();
void cli_creagroup();
void cli_delgroup();
void friend_histroy();
void cli_allgroup();
void cli_groupmember();
void cli_setgroup();
void cli_joingroup();
void cli_cleargroup();
void cli_groupchat();
void cli_grouphistroy();
void *grouprecv() //群聊天收包
{
    while (1)
    {
        recv_t(recv_pack, sock_fd);
        pthread_mutex_lock(&groups);
        printf("%s:%s\n", recv_pack->send_name, recv_pack->work);
        if (flag == 0)
            pthread_exit(0);
        pthread_mutex_unlock(&groups);
    }
}
void cli_groupchat() //群聊
{
    printf("请输入群聊的群号：");
    scanf("%d", &send_pack->send_nums);
    printf("聊天中..........(输入~exit,退出聊天)\n");
    printf("%s:",recv_pack->send_name);
    scanf("%s",recv_pack->work);
    send_t(recv_pack,sock_fd);
}
void cli_cleargroup()
{
    printf("请选择要解散的群聊群号：");
    scanf("%d", recv_pack->id);
    send_t(send_pack, sock_fd);
}
void cli_joingroup() //添加群聊
{
    printf("请输入需要添加群聊的群号:\n");
    scanf("%d", &send_pack->id);
    send_t(send_pack, sock_fd);
}
void cli_setgroup() //设置管理员
{
    printf("请选择群号:");
    scanf("%d", &send_pack->id);
    printf("\n请选择设置的成员");
    scanf("%s", send_pack->recv_name);
    send_t(send_pack, sock_fd);
}
void cli_creagroup() //创群
{
    printf("创建群名:");
    scanf("%s", send_pack->recv_name);
    send_t(send_pack, sock_fd);
}
void cli_delgroup() //退群
{
    printf("需要退出的群号：");
    scanf("%d", &send_pack->id);
    send_t(send_pack, sock_fd);
}
void chatjuti()
{
    while (1)
    {
        if (strcmp(recv_pack->work, "~exit") == 0)
            break;
        printf("%s:%s\n", recv_pack->recv_name, recv_pack->work);
        strcpy(send_pack->send_name, recv_pack->send_name);
        strcpy(send_pack->recv_name, recv_pack->recv_name);
        printf("%s:", recv_pack->send_name);
        scanf("%s", send_pack->work);
        send_t(send_pack, sock_fd);
        if (strcmp(send_pack->work, "~exit") == 0)
            break;
        recv_t(recv_pack, sock_fd);
    }
    printf("退出聊天");
}
void friend_histroy()
{
    printf("需要查看的好友:");
    scanf("%s", send_pack->recv_name);
    send_t(send_pack, sock_fd);
}
void *nextst()
{
    while (1)
    {
        pthread_mutex_lock(&get);
        while (tiao > 0)
        {
            pthread_cond_wait(&toget, &get);
        }
        tiao++;
        printf("---欢迎来到简单的聊天室---\n");
        printf("-----welcome %s------\n", send_pack->send_name);
        printf("%10s", "d.加好友\n");
        printf("%10s", "e.删除好友\n");
        printf("%10s", "f.显示全部好友和状态\n");
        printf("%10s", "g.私聊\n");
        printf("%10s", "h.创建群\n");
        printf("%10s", "i.退群\n");
        printf("%10s", "o.显示所有群\n");
        printf("%10s", "p.显示群成员\n");
        printf("%10s", "r.群权限设置\n");
        printf("%10s", "s.解散群聊天\n");
        printf("%10s", "t.加入群聊天\n");
        printf("%10s", "k.群聊\n");
        printf("%10s", "l.传输文件\n");
        printf("%10s", "j.消息中心\n");
        printf("%10s", "n.查看好友历史\n");
        printf("%10s", "m.查看群消息\n");
        printf("%10s", "w.查看群历史\n");
        printf("%10s", "q.退出\n");
        if (mes == 1)
        {
            printf("你有新的消息，快去消息中心处理吧\n");
        }
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
        {
            cli_chatfriend();
            break;
        }
        case 'h':
            cli_creagroup();
            break;
        case 'i':
            cli_delgroup();
            break;
        case 'o':
            cli_allgroup();
            break;
        case 'p':
            cli_groupmember();
            break;
        case 'j':
            cli_message();
            break;
        case 'n':
            friend_histroy();
            break;
        case 's':
            cli_cleargroup();
        case 'q':
        {
            close(sock_fd);
            exit(0);
        }
        case 'k':
            cli_groupchat();
            break;
        case 'r':
            cli_setgroup();
            break;
        case 't':
            cli_joingroup();
            break;
        case 'w':
            cli_grouphistroy();
            break;
        case '\n':
        {
            tiao == 0;
            break;
        }
        default:
        {
            printf("无效输入，请重试\n");
            tiao--;
        }
        }
        pthread_mutex_unlock(&get);
        if (tiao > 0)
        {
            pthread_cond_signal(&forget);
        }
    }
    return NULL;
}
void cli_allgroup()
{
    printf("-------所有群聊-------\n");
    send_t(send_pack, sock_fd);
}
void cli_groupmember()
{
    printf("-------所有成员-------\n");
    printf("需要查看群成员的群号:\n");
    scanf("%d", &send_pack->id);
    printf("-----所有群群成员-----\n");
    send_t(send_pack, sock_fd);
}
void recvs() //收数据包
{
    sleep(1);
    int t;
    pthread_t groupid;
    while (1)
    {
        pthread_mutex_lock(&get);
        while (tiao == 0)
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
            printf("你一共有%s个好友(0.下线 1.上线)\n", recv_pack->work);
            t = atoi(recv_pack->work);
            for (int i = 0; i < t; i++)
            {
                if ((recv(sock_fd, pthead, sizeof(pthnode), 0)) < 0)
                    my_err("recv", __LINE__);

                printf("%s  %d\n", pthead->work, pthead->status);
            }
            // printf("%s  %d", recv_pack->work, recv_pack->status);
            break;
        }
        case 'g':
        {
            chatjuti();
            break;
        }
        case 'h':
        {
            printf("%s", recv_pack->work);
            printf("群名：%s 群号：%d\n", recv_pack->recv_name, recv_pack->send_nums);
            break;
        }
        case 'i':
        {
            printf("%s\n", recv_pack->work);
            break;
        }
        case 'n':
        {
            printf("一共有%d条消息\n", recv_pack->id);
            int sum = recv_pack->id;
            for (int i = 0; i < sum; i++)
            {
                recv(sock_fd, (void *)pthead, sizeof(pthnode), 0);
                printf("%s:%s\n", pthead->name, pthead->work);
            }
            break;
        }
        case 'o':
        {
            printf("一共有%d个群聊\n", recv_pack->id);
            int sum = recv_pack->id;
            for (int i = 0; i < sum; i++)
            {
                recv(sock_fd, (void *)grohead, sizeof(groupnode), 0);
                printf("群号:%d\n", grohead->id);
            }
            break;
        }
        case 'p':
        {
            printf("该群聊共有%d个成员\n", recv_pack->id);
            int sum = recv_pack->id;
            for (int i = 0; i < sum; i++)
            {
                recv(sock_fd, (void *)grohead, sizeof(groupnode), 0);
                printf("群号:%d 成员:%s\n", grohead->id, grohead->name);
            }
            break;
        }
        case 'r':
        {
            printf("%s\n", recv_pack->work);
            break;
        }
        case 's':
        {
            printf("%s\n", recv_pack->work);
            break;
        }
        case 't':
        {
            printf("%s\n", recv_pack->work);
            break;
        }
        case 'k': //群聊
        {
            flag = 1;
            if (strcmp(recv_pack->work, "对不起，你没有加入群聊\n") == 0)
            {
                printf("%s", recv_pack->work);
                break;
            }
            while (1)
            {
                pthread_mutex_lock(&groups);
                printf("%s:", send_pack->send_name);
                scanf("%s", send_pack->work);
                printf("\n");
                pthread_mutex_unlock(&groups);
                if (strcmp(send_pack->work, "~exit") == 0)
                    flag = 0;
                if (flag == 0)
                    break;
                send_t(send_pack, sock_fd);
                if (groupflag == 1)
                {
                    pthread_create(&groupid, NULL, grouprecv, NULL);
                    pthread_detach(groupid);
                    groupflag = 0;
                }
            }
            break;
        } 
        case 'w':   //查询群聊历史
        {
             pthnode *t=pthead;
             int num;
             printf("%s\n",recv_pack->work);
             if(strcmp(recv_pack->work,"你没有加入到该群聊")==0)
             break;
             num=recv_pack->id;
             for(int i=0;i<num;i++)
             {
                 recv(sock_fd,t,sizeof(pthnode),0);
                 printf("%s:%s\n",t->name,t->work);
             }
        }
        case 'j':
        {
            mes = 0;
            printf("你一共有%s条消息\n", recv_pack->work);
            printf("快来处理一下吧,你的消息\n");
            t = atoi(recv_pack->work);
            pack *retpack = (pack *)malloc(sizeof(pack)); //返回包
            retpack->send_id = recv_pack->send_id;
            for (int i = 0; i < t; i++)
            {
                recv(sock_fd, (void *)pthead, sizeof(pthnode), 0);
                switch (pthead->status)
                {
                case 1:
                {
                    printf("%s想添加你为好友(yes.同意 no.拒绝)\n", pthead->name);
                    scanf("%s", retpack->work);
                    strcpy(retpack->send_name, recv_pack->send_name);
                    strcpy(retpack->recv_name, pthead->name);
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
                    printf("%s发出申请加入群聊%s(yes.同意 no.拒绝)\n", pthead->name, pthead->work);
                    scanf("%s", retpack->work);
                    strcpy(retpack->send_name, recv_pack->send_name);
                    strcpy(retpack->recv_name, pthead->name);
                    send_t(retpack, sock_fd);
                    break;
                }
                case 4:
                {
                    printf("%s已经同意你的好友请求\n", recv_pack->recv_name);
                    break;
                }
                case 5:
                {
                    printf("你已经成功加入群聊%s\n", pthead->work);
                    break;
                }
                case 6:
                {
                    cf = 1;
                    printf("有你的私聊消息，去私聊中看看吧 from:%s\n", pthead->name);
                    break;
                }
                case 7:
                {
                    printf("你的离线时收到%s:%s\n", pthead->name, pthead->work);
                    break;
                }
                case 8:
                {
                    printf("%s%s\n", pthead->name, pthead->work);
                    break;
                }
                case 9:
                {
                    printf("%s%s\n", pthead->name, pthead->work);
                    break;
                }
                default:
                    break;
                }
            }
        }
        }
        recv_t(recv_pack, sock_fd);
        pthread_mutex_unlock(&get);
        if (tiao == 0)
            pthread_cond_signal(&toget);
    }
}
void cli_selfriend()
{
    send_t(send_pack, sock_fd);
    printf("--------好友列表-------\n");
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
void cli_grouphistroy()
{
    printf("请输入需要查询历史记录的群号：");
    scanf("%s", send_pack->recv_nums);
    send_t(send_pack, sock_fd);
}
void my_err(char *err_string, int line)
{
    fprintf(stderr, "line %d  ", line);
    perror(err_string);
    //exit(1);
}
void send_t(pack *s, int fd)
{
    if (send(fd, s, sizeof(pack), 0) < 0)
        my_err("send", __LINE__);
}
void recv_t(pack *s, int fd)
{
    if ((recv(fd, s, sizeof(pack), 0)) < 0)
        my_err("recv", __LINE__);
    if (s->status == 1)
    {
        mes = 1;
    }
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
    pthread_create(&pid, NULL, nextst, NULL);
    pthread_detach(pid);
    recvs();
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
    send_t(send_pack, sock_fd);
}
void cli_chatfriend()
{
    printf("聊天中..........(输入~exit,退出聊天)\n");
    if (cf == 0)
    {
        printf("请输入需要私聊的用户姓名：");
        scanf("%s", send_pack->recv_name);
        printf("%s:", send_pack->send_name);
        scanf("%s", send_pack->work);
        send_t(send_pack, sock_fd);
    }
    else
    {
        cf = 0;
        send_t(send_pack, sock_fd);
    }
}
int main()
{
    struct sockaddr_in cid;
    recv_pack = (pack *)malloc(sizeof(pack));
    send_pack = (pack *)malloc(sizeof(pack));
    pthead = (pthnode *)malloc(sizeof(pthnode));
    grohead = (groupnode *)malloc(sizeof(groupnode));
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
