#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include<stdio.h>
#define CLOSE "\001\033[0m\002"                 // 关闭所有属性
#define BLOD  "\001\033[1m\002"                 // 强调、加粗、高亮
#define BEGIN(x,y) "\001\033["#x";"#y"m\002"    // x: 背景，y: 前景

int main(void)
{
    while (1)
    {   
        read_history(NULL);
        char *str = readline(BEGIN(49, 34)"Myshell $ "CLOSE);
        add_history(str);
        write_history();
        free(str);
    }
}