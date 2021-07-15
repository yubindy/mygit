#include "chatroom.h"
pack *recv_pack;
pack *send_pack;
void delu(int sock_fd);
void chose();
void cli_find(int sock_fd);
void cli_sign(int sock_fd);
void cli_regist(int sock_fd);
void cli_chuli(int sock_fd);
void *body(void *arg);
void cli_delu(int sock_fd)
{
    while (1)
    {
        printf("---欢迎来到简单的聊天室---\n");
        printf("%5s", "a.登陆\n");
        printf("%5s", "b.注册\n");
        printf("%5s", "c.找回密码\n");
        printf("%5s", "q.退出\n");
        printf("----------------------------\n");
        send_pack->cho = fgetc(stdin);
        switch (send_pack->cho)
        {
        case 'a':
            cli_sign(sock_fd);
            return;
        case 'b':
            cli_regist(sock_fd);
            return;
        case 'c':
            cli_find(sock_fd);
            return;
        case 'q':
            exit(0);
        default:
            printf("无效输入，请重试\n");
        }
    }
}
void cli_sign(int sock_fd)
{
    char *mima;
    while (1)
    {
        printf("账号:");
        scanf("%d", send_pack->send_nums);
        mima = getpass("\n密码："); //密码不回显
        strncpy(send_pack->work, mima, 20);
        send_t(send_pack, sock_fd);
        recv_t(recv_pack, sock_fd);
        if (strncpy("yes", recv_pack->work, 3) == 0)
            break;
    }
    printf("登陆成功\n");
}
void cli_regist(int sock_fd)
{
    send_pack->cho = 'b';
    printf("请输入昵称：");
    scanf("%d", send_pack->send_name);
    printf("请输入密码：");
    scanf("%s", send_pack->work);
    while (1)
    {   
        printf("请对于以下密保问题作出选择并输入答案\n");
        printf("1.你的大学是：\n");
        printf("2.你的父亲是：\n");
        printf("3.你的爱好是：\n");
        scanf("%d", send_pack->id); //存贮选项
        if(send_pack->id==1||2||3)
        break;
    }
    scanf("%s", send_pack->nums);
    send_t(send_pack, sock_fd);
    recv_t(recv_pack, sock_fd);
    printf("账号：%d", recv_pack->send_nums);
    printf("注册成功\n");
    cli_delu(sock_fd);
}
void cli_find(int sock_fd)
{  
    char t[10];
    scanf("请输入账号：%d", send_pack->send_nums);
    send_t(send_pack, sock_fd);
    recv_t(recv_pack, sock_fd);
    switch (recv_pack->id)
    {
    case 1:
         printf("你的大学是：\n");
        break;
    case 2:
        printf("你的父亲是：\n");
        break;
    case 3:
        printf("你的爱好是：\n");
        break;
    }
    scanf("%s",t);
    if(strcmp(t,recv_pack->nums)==0)
    printf("该账号密码为:%s",recv_pack->work);
    cli_delu(sock_fd);
}
int main()
{
    int sock_fd;
    struct sockaddr_in cid, lid;
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
    cid.sin_port = port;
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