#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void rand_file(char *s) //生成随机目录
{

        int a, b;
        srand((unsigned)time(NULL));
        a = rand() % 7 + 3;
        for (int i = 0; i < a; i++)
        {
                b = rand() % 26;
                s[i] = 'a' + b;
        }
        return;
}

int main()
{
        char files[100], rands[20];
        int fd;
        getcwd(files, sizeof(files));
        memset(rands,0,sizeof(rands));
        rand_file(rands);
        files[strlen(files)] = '/';
        strncat(files, rands, sizeof(rands));
        printf("%s",files);
        return 0;
}