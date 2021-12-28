#include <stdio.h>
int main()
{
    char s[10];
    system("ls | grep in | wc -l > /dev/stdout");
    perror("sysstem");
    // scanf("%s",s );
    // printf("%s",s);
    return 0;
}