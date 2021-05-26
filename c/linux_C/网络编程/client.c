#include "c_s.h"
int main(int argc, char **argv)
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
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0)
    {
        my_err("socket", __LINE__);
    }
    memset(server_addr, 0, sizeof(server_addr));
    for (int i = 0; i < argc; i++)
    {
        if (strcmp("-p", argv[i]) == 0)
        {
            server_port = atoi(argv[i + 1]);
            if (server_port < 0 || server_port > 65535)
            {
                printf("innvalid server_addr.sin_port\n");
                exit(1);
            }
            else
                server_addr.sin_port = htons(server_port);
        }
        else if(strcmp("-a",argv[i])==0)
        {
            if (inet_aton(argv[i + 1], &server_addr.sin_addr) == 0)
            {
                printf("innvalid server_addr.sin_addr\n");
                exit(1);
            }
            continue;
        }
    }
    server_addr.sin_family = AF_INET;
    if (connect(sock_fd, (struct aockaddr *)&(server_addr), sizeof(server_addr)) < 0)
    {
        my_err("connect", __LINE__);
    }
    
}