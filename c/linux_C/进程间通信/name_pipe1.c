#include"Linux_c.h"
#define size 1024;
int main()
{  
   char buf[size];
   int rfd,wfd;
   int len;
   umask(0);
   if(mkfifo("writefifo",S_IFIFO|0666))
   {
       printf("Can not creat FIFO %s because %s","writefifo",strerror(errno));
       exit(1);
   }
   umask(0);
   if(mkfifo("readfifo",S_IFIFO|0666))
   {
       printf("Can not creat FIFO %s because %s","readfifo",strerror(errno));
       exit(1);
   }
   while((rfd=open("readfifo",O_RDONLY)==-1))
   sleep(1);
   while(1)
   {
       printf("Servant:");
       fgets(buf,size,stdin);
       buf[strlen(buf)-1]='\0';
       if(strcmp(buf,"quit",4)==0)
       {
           close(wfd);
           unlink("writefifo");
           close(rfd);
           exit(0);
       }
       write(wfd,buf,strlen(buf));
       len=read(rfd,buf,size);
       if(len>0)
       {
           buf[len]='\0';
           printf("CLient:%s",buf);
       }
   }
}