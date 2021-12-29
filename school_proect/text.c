#include <stdio.h>
#include <unistd.h>
#include <linux/limits.h>
#include <stdlib.h>
#include <libgen.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char s[10];
    char t[100];
    printf("%s", argv[0]);
    strncpy(t,argv[0],100);
    for (int i = strlen(t); i >= 0; i--)
    {
        if (t[i] == '/')
        {
            t[i] = '\0';
            break;
        }
    }
    chdir(t);
    
    system("ls  *.in > /dev/stdout");
    return 0;
}