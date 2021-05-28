#include "c_s.h"
#define point 4507
#define listsize 15
#define names 0
#define pass 1
struct user
{
  char username[32];
  char password[32];
};
struct user users[3] = {
    {"zhaozeyu", "123456"}, {"cl1", "cl1"}, {"asdfg", "123456"}};
int find_name(int *t, const char *name)
{
  if (name == NULL)
    return -1;
  for (int i = 0; i < 3; i++)
  {
    if (strcmp(users[i].username, name) == 0)
    {
      *t = i;
      return 1;
    }
  }
  return -1;
}
void send_sd(int fd, const char *t)
{
  if (send(fd, t, strlen(t), 0) < 0)
  {
    my_err("send", __LINE__);
  }
}
int main()
{
  int sock_fd, new_fd;
  int flag = 0;
  int user_num = 0;
  struct sockaddr_in client_addr, server_addr;
  socklen_t client_len = sizeof(client_addr);
  char cu[32]; //缓存区大小
  pid_t pid;
  int ret;
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
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(point);
  server_addr.sin_addr.s_addr = INADDR_ANY;
  if (bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
  {
    my_err("bind", __LINE__);
  }
  if (listen(sock_fd, listsize) < 0)
  {
    my_err("listen", __LINE__);
  }
  while (1)
  {
    if ((new_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &client_len)) < 0)
    {
      my_err("accept", __LINE__);
    }
    printf("server accpet a new client,ip:%s\n", inet_ntoa(client_addr.sin_addr));
    if ((pid = fork()) == 0)
    {
      while (1)
      {
        if ((ret = recv(new_fd, cu, sizeof(cu), 0)) < 0)
        {
          my_err("recv", __LINE__);
        }
        if (flag == names) //如果是用户名
        {
          switch (find_name(&user_num, cu))
          {
          case -1:
            send_sd(new_fd, "no find the username\n");
            break;
          case 1:
            flag = pass;
            send_sd(new_fd, "yes");
            break;
          }
        }
        else if (flag == pass) //如果是密码
        {
          if (strcmp(users[user_num].password, cu) == 0)
          {
            send_sd(new_fd, "yes");
            send_sd(new_fd, "welocme sign in the server");
            printf("%s login\n", users[user_num].username);
            break;
          }
          else
          {
            send_sd(new_fd, "the passwor is error");
            flag = 0;
          }
        }
      }
      close(sock_fd);
      close(new_fd);
      exit(0);
    }
    else
      close(new_fd); //父进程关闭该套接字描述符
  }
  printf("关闭服务器\n");
  return 0;
}