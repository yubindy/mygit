#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/stat.h>
# define buf_size 256
# define path_name "/tmp"
# define pid_id 32
# define server_msg 1
# define client_msg 2
int main(void)
{
    struct mymsgbuf{
        long msgtype;
        char string[buf_size];
    }msgbuffer;
    int qid;
    int msglen;
    key_t msgkey;
    if(msgkey=ftok(path_name,pid_id)==-1)
    {
        printf("ftok error\n");
        exit(1);
    }
    if(msgget(msgkey,IPC_CREAT|0660)==-1)
    {
        printf("msgget error\n");
        exit(1);
    }
    while(1)
    {
        printf("server :");
        fgets(msgbuffer.string,buf_size,stdin);
        if(strncmp("exit",msgbuffer.string,4)==0)
        {
            msgctl(qid,IPC_RMID,NULL);
            exit(1);
        }
        msgbuffer.string[strlen(msgbuffer.string-1)]='\0';
        msgbuffer.msgtype=server_msg;
       if(msgsnd(qid,&msgbuffer,strlen(msgbuffer.string)+1,0)==-1)
       {
           printf("Server msgsnd error!\n");
           exit(1);
       }
       if(msgrcv(qid,&msgbuffer,buf_size,client_msg,0)==-1)
       {
           printf("Server msgsnd error!\n");
           exit(1);
       }
       printf("Client:%s\n",msgbuffer.string);
    }
    exit(0);
}
