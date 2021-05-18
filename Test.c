#include <stdio.h>
int main(int argc, char const *argv[])
{
    #ifdef __linux__
    printf("sadfjkhdafd\n");
    #endif    
    #ifdef __WIN32
    printf("dasfeffe\n");
    #endif
    return 0;
}
