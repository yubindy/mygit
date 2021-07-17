#include<stdio.h>
#include <string.h>
#include<sys/stat.h>
#include <unistd.h>
#include <linux/limits.h>
#include<stdlib.h>
#include<sys/types.h>
#include <signal.h>
#include<errno.h>
#include<time.h>
#include <grp.h>
#include <dirent.h>
#include <pwd.h>
#define MAX_SIZE 80;        //最大的行宽
int space=MAX_SIZE;         //剩余空间
int max_long=0;        //每个目录下最长的文件名
void work_dir(char *path,int flag);
void my_error(const char *error_string, int line);
void simple_play(char *name);
void all_play(char *name,struct stat buf);
void display_R(int flag,char *pastfile[],int num);
void display_type(char *name,int flag);

//颜色选择
#define CLOSE printf("\033[0m"); //关闭彩色字体
#define RED printf("\033[31m"); //红色字体
#define GREEN printf("\033[36m");//绿色字体
#define YELLOW printf("\033[33m");//黄色字体
#define BLUE printf("\033[34m");//蓝色字体
#define PURPLE printf("\033[35m");//紫色
#define WHITE printf("\033[37m");//白色
#define DD printf("\033[34m"); //浅绿色

void colorprint(struct stat buf)
{
   
    if (S_ISLNK(buf.st_mode))
    {
   
        
        RED
    }
    else if (S_ISREG(buf.st_mode))
    {
   
        GREEN
        
    }
    else if (S_ISDIR(buf.st_mode))
    {
   
        YELLOW
    }
    else if (S_ISCHR(buf.st_mode))
    {
   
        BLUE
    }
    else if (S_ISBLK(buf.st_mode))
    {
   
        WHITE
    }
    else if (S_ISFIFO(buf.st_mode))
    {
   
        PURPLE
    }
    else if (S_ISSOCK(buf.st_mode))
    {
   
        DD
    }
}
void my_error(const char *error_string, int line)
{
   
    fprintf(stderr, "line:%d",line);
    perror(error_string);
    
}
void simple_play(char *name) //无参数只输出名字
{
   
    printf("%s",name);
    int len=strlen(name);
    int i=0;
    for (i=0;i<max_long-len;i++)
    {
   
        printf(" ");
    }
    printf("  ");
    space=space-max_long-2;
    
    if (max_long>space)
    {
   
        printf("\n");
        space=80;
    }
}

void all_play(char *name,struct stat buf)
{
   
    struct passwd *p;
    struct group *g;
    GREEN
    g = getgrgid(buf.st_gid);
    p = getpwuid(buf.st_uid);
    if (g==NULL||p==NULL)
    {
      printf("无法打开文件\n");
        perror("getpwuid");
        return;
    }
    if (S_ISLNK(buf.st_mode))
    {
   
        printf("l");
    }
    else if (S_ISREG(buf.st_mode))
    {
   
        printf("_");
    }
    else if (S_ISDIR(buf.st_mode))
    {
   
        printf("d");
    }
    else if (S_ISCHR(buf.st_mode))
    {
   
        printf("c");
    }
    else if (S_ISBLK(buf.st_mode))
    {
   
        printf("b");
    }
    else if (S_ISFIFO(buf.st_mode))
    {
   
        printf("f");
    }
    else if (S_ISSOCK(buf.st_mode))
    {
   
        printf("s");
    }
    if (buf.st_mode & S_IRUSR)
    {
   
        printf("r");
    }
    else
        printf("-");
    if (buf.st_mode & S_IWUSR)
    {
   
        printf("w");
    }
    else
        printf("-");
    if (buf.st_mode & S_IXUSR)
    {
   
        printf("x");
    }
    else
        printf("-");

    if (buf.st_mode & S_IRGRP)
    {
   
        printf("r");
    }
    else
        printf("-");
    if (buf.st_mode & S_IWGRP)
    {
   
        printf("w");
    }
    else
        printf("-");
    if (buf.st_mode & S_IXGRP)
    {
   
        printf("x");
    }
    else
        printf("-");

    if (buf.st_mode & S_IROTH)
    {
   
        printf("r");
    }
    else
        printf("-");
    if (buf.st_mode & S_IWOTH)
    {
   
        printf("w");
    }
    else
        printf("-");
    if (buf.st_mode & S_IXOTH)
    {
   
        printf("x");
    }
    else
        printf("-");
    printf(" ");
    printf("%ld", buf.st_nlink);
    printf(" ");
    printf("%-5s", p->pw_name);
    printf("%-5s", g->gr_name);
    printf("%6ld", buf.st_size);
    printf(" ");
    int size = strlen(ctime(&buf.st_ctime));
    char timering[size + 1];
    strcpy(timering, ctime(&buf.st_ctime));
    timering[size - 1] = '\0';
    printf("%s", timering);
    printf(" ");
    CLOSE
    colorprint(buf);
    printf("%s", name);
    CLOSE
    printf("\n");
}
void display_R(int flag,char *pastfile[],int num)
{
   
    
    flag -= 4;
    int i;
    struct stat buf;
    char a[PATH_MAX];
    int k,j=0;
    char *temple=(char*)malloc(sizeof(char)* PATH_MAX);
    for (i=0;i<num;i++)
    {
   
        
        int l=strlen(pastfile[i]);
        strcpy(temple, pastfile[i]);
        temple[l] = '\0';
        for (k = 0, j = 0; k < strlen(pastfile[i]); k++)
            {
   
                if (pastfile[i][k] == '/')
                {
   
                    j = 0;
                    continue;
                }
                a[j++] = pastfile[i][k];
            }
            a[j] = '\0';
        if (strcmp(a,".")==0||strcmp(a,"..")==0)
        {
   
            continue;
        }
        if (lstat(pastfile[i], &buf) == -1)
        {
   
            printf("%s\n",pastfile[i]);
            my_error("lstat",__LINE__);
            continue;
        }
        if (S_ISDIR(buf.st_mode))
        {
   
            
            if (temple[l-1] != '/')
            {
   
                strcat(temple,"/");
            }
            if (flag == 0)
            {
   
                if (a[0]!= '.')
                {
   
                    work_dir(temple,flag+4);
                }
            }
            else if (flag == 1)
            {
   
                work_dir(temple,flag+4);
            }
            else if (flag == 2)
            {
   
                if (a[0] != '.')
                {
   
                    work_dir(temple,flag+4);
                }
            }
            else if (flag == 3)
            {
   
                work_dir(temple,flag+4);
            }
        }
        free(pastfile[i]);
    }
    free(temple);
}
void display_type(char *name,int flag)
{
      
    int temple=flag;
    if (flag==4|| flag==5||flag==7||flag==6)
    {
   
        flag-=4;
    }
    int i = 0, j = 0;
    char a[PATH_MAX];
    struct stat buf;

    for (i = 0, j = 0; i < strlen(name); i++)
    {
   
        if (name[i] == '/')
        {
   
            j = 0;
            continue;
        }
        a[j++] = name[i];
    }
    a[j] = '\0';

    if (lstat(name, &buf) == -1)
    {
   
        printf("%s",name);
        my_error("lstat",__LINE__);
        return;
    }

    if (flag == 0)
    {
   
        if (a[0] != '.')
        {
   
            colorprint(buf);
            simple_play(a);
            CLOSE
        }
    }
    else if (flag == 1)
    {
   
        colorprint(buf);
        simple_play(a);
        CLOSE
    }
    else if (flag == 2)
    {
   
        if (a[0] != '.')
        {
   
            
            all_play(a,buf);
            
        }
    }
    else if (flag == 3)
    {
   
        
        all_play(a,buf);
        
    }
    
}

void work_dir(char *path,int flag)
{
   
    
    DIR *dir;
    int num=0;
    int i=0;
    struct dirent*ptr;
    if ((dir=opendir(path))==NULL)
    {
   
        my_error("opendir",__LINE__);
        return;
    }
    while ((ptr=readdir(dir))!=NULL)
    {
   
        num++;
        if ((strlen(ptr->d_name)>max_long))
        {
   
            max_long=strlen(ptr->d_name);
        }
    }
    closedir(dir);
    if ((dir=opendir(path))==NULL)
    {
   
        my_error("opendir",__LINE__);
        return;
    }
    char *filenames[num];
    for (i = 0;i < num;i++)
    {
   
        filenames[i] = (char*)malloc(sizeof(char) * PATH_MAX);
        if (filenames[i]==NULL)
        my_error("malloc",__LINE__);
    }
    
    int len=strlen(path);
    if (filenames==NULL)
    {
   
        my_error("malloc",__LINE__);
    }
    for (i=0;i<num;i++)
    {
      if ((ptr=readdir(dir))==NULL)
        {
   
            my_error("opendir",__LINE__);
            return;
        }
        strncpy(filenames[i],path,len);
        filenames[i][len]='\0';
        strcat(filenames[i],ptr->d_name);
        
    }
    closedir(dir);
    printf("%s:\n",path);





        space =MAX_SIZE;
        int a[num];
        for (i=0;i<num;i++)
        {
    
            a[i]=i;
        } 
        int j,t; 

        for(j=0;j<num-1;j++) 

            {
   for(i=0;i<num-1-j;i++) 

             {
      if(strcmp(filenames[a[i]],filenames[a[i+1]])>=0)

                {
    

                t=a[i]; 

                a[i]=a[i+1]; 

                a[i+1]=t; 

                }

             }
            }

    for (i=0;i<num;i++)
    {
   
        display_type(filenames[a[i]],flag);
        
    }
    
    printf("\n");
    if (flag==4|| flag==5||flag==7||flag==6)
    {
   
        display_R(flag,filenames,num);
    }
}

int main(int argc, char **argv)
{
   
   // signal(SIGINT, SIG_IGN);
    char argustr[100];
    int count_arguments=0;
    struct stat buf;
    int i=1;
    for (i=1;i<argc;i++)
    {
      
        if (argv[i][0]=='-')
        {
   
        count_arguments++;
        strcat(argustr, argv[i]);
        }
        
    }
    int flag=0;
//获取ls的参数，a=1,l=2,R=4;
    int l=strlen(argustr);
    int judge_a=0,judge_l=0,judge_R=0;
    for (i=0;i<l;i++)
    {
   
        if (argustr[i]=='-')
        {
   
            continue;
        }
        else if (argustr[i]=='a'&&judge_a==0)
        {
   
             flag++;
             judge_a=1;
        }
        else if (argustr[i]=='l'&&judge_l==0)
        {
   
             flag=flag+2;
             judge_l=1;
        }else if (argustr[i]=='R'&&judge_R==0)
        {
   
             flag=flag+4;
             judge_R=1;
        }
        else
        {
   
            printf("arguments don't support");
            exit(0);           
        }
    }
    char path[PATH_MAX];       //无参数就作用于当前目录。
    if (argc==(count_arguments+1))
    {
   
        strcpy(path,"./");
        path[2]='\0';
        work_dir(path,flag);
    }
    for (i=1;i<argc;i++)
    {
   
        if (argv[i][0]=='-')
        {
   
            continue;
        }
        if (lstat(argv[i],&buf)==-1)
        {
   
            my_error("lstat",__LINE__);

            continue;
        }
        if (S_ISDIR(buf.st_mode)) //是目录就先处理后遍历文件
                {
   
            int l=strlen(argv[i]);
            if (argv[i][l-1]!='/')
            {
   
                strcpy(path,argv[i]);
                path[l]='/';
                path[l+1]='\0';
            }
            else
            {
   
                strcpy(path,argv[i]);
                path[l]='\0';
            }
            work_dir(path,flag);
        }
        else //是文件时直接打印
        {
   
            display_type(path,flag);
        }
    }
        
}