#include "chatroom.h"
pack *recv_pack = (pack *)malloc(sizeof(pack));
pack *send_pack = (pack *)malloc(sizeof(pack));
void delu(int sock_fd);
void chose();
void cli_find(int sock_fd);
void cli_sign(int sock_fd);
void cli_regist(int sock_fd);
void find_work(int sock_fd);
void chuli(int sock_fd);
void delu(int sock_fd)
{
    printf("---欢迎来到简单的聊天室---\n");
    printf("%5s", "a.登陆\n");
    printf("%5s", "b.注册\n");
    printf("%5s", "c.找回密码\n");
    printf("%5s", "q.退出\n");
    printf("----------------------------\n");
    char t = fgetc(stdin);
    switch (t)
    {
    case 'a':
        cli_sign(sock_fd);
        break;
    case 'b':
        cli_regist(sock_fd);
        break;
    case 'c':
        cli_find(sock_fd);
        break;
    case 'q':
        exit(0);
    }
}
void chose()
{
    printf("---欢迎来到简单的聊天室---\n");
    printf("%5s", "d.登陆\n");
    printf("%5s", "e.注册\n");
    printf("%5s", "f.退出\n");
    printf("%5s", "g.找回密码\n");
    printf("%5s", "h.退出登陆\n");
    printf("----------------------------\n");
}
void cli_find(sock_fd)
{
}
void cli_sign(int sock_fd)
{
    char *mima;
    while (1)
    {
        printf("账号:");
        scanf("%d", send_pack->recv_nums);
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
    send_pack->cho='b';
    printf("请输入昵称：");
    scanf("%d", send_pack->send_name);
    printf("请输入密码：");
    scanf("%s", send_pack->work);
    printf("请对于以下密保问题作出选择并输入答案\n");
    printf("1.你的大学是：");
    printf("\n2.你的父亲是：");
    printf("\n3.你的爱好是：");
    scanf("%d", send_pack->send_id); //存贮选项
    scanf("%s", send_pack->nums);
    send_t(send_pack, sock_fd);
    recv_t(recv_pack, sock_fd);
    printf("账号：%d", recv_pack->send_nums);
    printf("注册成功\n");
    delu(sock_fd);
}
void find_work(int sock_fd)
{
    //printf("")
}
// void chuli(int sock_fd)
// {
//     while (1)
//     {
//         char t = fgetc(stdin);
//         switch (t)
//         {
//         case 'd':
//             sign(sock_fd);
//             break;
//         case 'e':
//             zhuce(sock_fd);
//             break;
//         case 'f':
//              cli_regist(sock_fd);
//             break;
//         case 'g':
//             find_word(sock_fd);
//             break;
//         default:
//             printf("无效输入，请新输入\n");
//             break;
//         }
//     }
// }
int main()
{
    int sock_fd;
    struct sockaddr_in cid, lid;
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
    delu(sock_fd);
}