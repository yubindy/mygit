#include <stdio.h>

extern char ** environ;

int main()
{
    char ** envir = environ;
    
    while(*envir)
    {
        fprintf(stdout,"%s\n",*envir);
        envir++;
    }
    return 0;
}
