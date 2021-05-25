#include"c_s.h" 
#define point 4507
#define listsize 15
struct user{
    char username[32];
    char password[32];
};
int main()
{
   int sock_fd;
   struct sockaddr_in sock_addr;
   sock_fd=socket(AF_INET,SOCK_STREAM,0);
   if(sock_fd<0)
   {
     my_err("socket",__LINE__);
   }
   int opt_val=1;
   if(setsockopt(sock_fd,IPPROTO_TCP,SO_REUSEADDR,(void*)&opt_val,sizeof(int))<0)
   {
     my_err("setsockopt",__LINE__);
   }
   memset(sock_addr.sin_zero,0,sizeof(sock_addr.sin_zero));
   sock_addr.sin_family=AF_INET;
   sock_addr.sin_port=htons(point);
   sock_addr.sin_s_addr=htoms();
   if(bind(sock_fd,(struct sockaddr*)&sock_addr,sizeof(struct sockaddr_in))<0)
   {
     my_err("bind",__LINE__);
   }
   if(listen(sock_fd,listsize)<0)
   {
       my_err("listen",__LINE__);
   }
   
}