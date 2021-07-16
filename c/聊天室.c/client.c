#include "chatroom.h"
pack *recv_pack;
pack *send_pack;
void delu(int sock_fd);
void chose();
void cli_find(int sock_fd);
int cli_sign(int sock_fd);
void cli_regist(int sock_fd);
void cli_chuli(int sock_fd);
void *body(void *arg);
void next_jiemain(int sock_fd);
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
void cli_delu(int sock_fd)
{   
    int pand=0;
    while (1)
    {
        printf("---欢迎来到简单的聊天室---\n");
        printf("%5s", "a.登陆\n");
        printf("%5s", "b.注册\n");
        printf("%5s", "c.找回密码\n");
        printf("%5s", "q.退出\n");
        printf("----------------------------\n");
        scanf("%c", &send_pack->cho);
        printf("文件描述符%d\n",send_pack->send_id);
        switch (send_pack->cho)
        {
        case 'a':
            pand=cli_sign(sock_fd);
            if(pand==0)
            break;
            else
            next_jiemain(sock_fd);
        case 'b':
            cli_regist(sock_fd);
            break;
            ;
        case 'c':
            cli_find(sock_fd);
            break;
        case 'q':
            exit(0);
        default:
            printf("无效输入，请重试\n");
        }
        scanf("%c", &send_pack->cho);
    }
}
void next_jiemain(int sock_fd)
{
    return;
}
int cli_sign(int sock_fd)
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
void cli_regist(int sock_fd)
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
void cli_find(int sock_fd)
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
int main()
{
    int sock_fd;
    struct sockaddr_in cid;
    recv_pack = (pack *)malloc(sizeof(pack));
    send_pack = (pack *)malloc(sizeof(pack));
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
    fgets(nums, 50, stdin);
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
    cli_delu(sock_fd);
}