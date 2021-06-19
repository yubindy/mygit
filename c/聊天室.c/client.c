#include "c_s.h"
char nums[50];
void delu()
{
    printf("----------------------------\n");
    printf("%5s","a.登陆\n");
    printf("%5s","b.注册\n");
    printf("%5s","q.退出\n");
    printf("%5s","q.找回密码\n");
    printf("----------------------------\n");
}
void sign()
{   
    char st1[20],st2[20];
    printf("账号:");
    fgets(stl1,20,stdin);
    printf("密码:");
    fgets(stl2,20,stdin);
}
void chuli()
{
    char t = fgetc(stdin);
    switch (t)
    {
        case 'a':
        
        case "b":
        case "q":

    }
}
int main()
{
    int sock_fd;
    struct sockaddr_in cid, lid;
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0)
    {
        my_err("socket", __LINE__);
    }
    memset(&cid, 0, sizeof(cid));
    cid.sin_port = port;
    cid.sin_family = AF_INET;
    printf("请输入服务器地址:");
    fgets(nums, 50, stdin);
    cu[strlen(nums) - 1] = '\0';
    cid.sin_family = inet_aton(nums, &cid.sin_addr);
    if (connect = (sock_fd, (struct sockaddr *)&cid), sizeof(cid) < 0)
    {
        my_err("connect", __LINE__);
    }
    delu();
    chuli();
}