#include <bits/stdc++.h>
int main(int argc, char *argv[]) {
    int p1[2], p2[2];
    if (pipe(p1) < 0) {
        printf("pipe() failed\n");
        exit(1);
    }
    if (pipe(p2) < 0) {
        printf("pipe() failed\n");
        exit(1);
    }
    int pid;
    char s = 's';
    int ret = fork();
    if (ret == 0) {
        pid = getpid();
        read(p1[0], &s, 1);
        printf("%d: received ping\n", pid);
        write(p2[1], &s, 1);
        exit(0);
    } else if (ret > 0) {
        pid = getpid();
        write(p1[1], &s, 1);
        read(p2[0], &s, 1);
        printf("%d: received pong", pid);
        exit(0);
    } else if (ret < 0) {
        printf("fork fail");
    }
    exit(0);
}