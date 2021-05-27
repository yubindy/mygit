#include "c_s.h"
void send_infor(int sock_fd, const char *t)
{
    char cu[32];
    int flag = 0;
    while (!flag)
    {
        printf("%s:", t);
        fgets(cu, 32, stdin);
        if (send(sock_fd, cu, sizeof(cu), 0) < 0)
        {
            my_err("send", __LINE__);
        }
        if (recv(sock_fd, cu, sizeof(cu), 0) < 0)
        {
            my_err("recv", __LINE__);
        }
        if (strcmp(cu, "yes") == 0)
            flag = 1;
        else
            printf("\n%s error inupt\n", t);
    }
}
int main(int argc, char *argv[])
{
    int sock_fd;
    int server_port;
    struct sockaddr_in server_addr;
    char cu[32]; //缓存区大小
    if (argc != 5)
    {
        printf("usags:[-p] [-ser_port] [-a] [ser_arrres]");
        exit(1);
    }
    memset(&server_addr, 0, sizeof(server_addr));
    for (int i = 0; i < argc; i++)
    {
        if (strcmp("-p", argv[i]) == 0)
        {
            server_port = atoi(argv[i + 1]);
            if (server_port <= 0 || server_port > 65535)
            {
                printf("innvalid server_addr.sin_port\n");
                exit(1);
            }
            else
                server_addr.sin_port = htonl(server_port);
            printf("port:%d\n", server_port);
        }
        else if (strcmp("-a", argv[i]) == 0)
        {
            printf("%s", argv[i + 1]);
            if (inet_aton(argv[i + 1], &server_addr.sin_addr) == 0)
            {
                printf("innvalid server_addr.sin_addr\n");
                exit(1);
            }
            continue;
        }
    }
    server_addr.sin_family = AF_INET;
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0)
    {
        my_err("socket", __LINE__);
    }
    if (connect(sock_fd, (struct sockaddr *)&(server_addr), sizeof(struct sockaddr)) < 0)
    {
        my_err("connect", __LINE__);
    }
    send_infor(sock_fd, "username");
    send_infor(sock_fd, "password");
    if (recv(sock_fd, cu, sizeof(cu), 0) < 0)
    {
        my_err("recv", __LINE__);
    }
    printf("%s", cu);
    printf("\n");
    return 0;
}