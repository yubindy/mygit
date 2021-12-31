#ifndef MIGONG.H
#define MIGONG .H
#include "queue.h"
#include <stdio.h>
#include <unistd.h>
#include <cstring>
#include <linux/limits.h>
#include <stdlib.h>
#include <libgen.h>
#include <string.h>
#include <vector>
void my_err(const char *err_string, int line) //错误处理函数
{

    fprintf(stderr, "line:%d", line);
    perror(err_string);
    exit(1);
}
#endif