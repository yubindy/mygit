#include "c_s.h"
int main()
{
    int lid, cld;
    struct sockaddr_in lidaddr, cidaddr;
    int num[32];
    lid = socket(AF_INET, SOCK_STREAM, 0);
    int opt_val = 1;
    if (setsockopt(lid, SOL_SOCKET, SO_REUSEADDR, (void *)&opt_val, sizeof(int)) < 0)
    {
        my_err("setsockopt", __LINE__);
    }
    memset(lidaddr, 0, sizeof(lidaddr));
    lidaddr.sin_family = AF_INET;
    lidaddr.sin_port = htons(point);
    lidaddr.sin_addr.s_addr = INADDR_ANY;
    bind(lid, (sockaddr *)&lid, sizeof(lidaddr));
    listen(lid, 15);
    fd_set rest, alrest;
    int t, maxfd;
    maxfd = lid;
    rest = alrest;
    int opt_val = 1;
    FD_ZERO(&alrest);
    fd_set(lid, &alrest);
    while (1)
    {
        rest = alrest;
        t = select(lid + 1, &rest, NULL, NULL, NULL);
        if (t < 0)
        {
            my_err("select", __LINE__);
        }
        if (fd_isset(lid, &rest))
        {
            cld = accept(lid, (sockaddr *)&lidaddr, sizeof(lidaddr));
            fd_set(cld, alrest);
            if (maxid < cld)
                maxid = cld;
            if (t == 1)
                continue;
        }
        for (int i = lid + 1, i <= maxid; i++)
        {
            if (fd_isset(i, &alrest))
            {
                if (read(i, num, sizeof(buf)) == 0)
                {
                    close(i);
                    FD_CLR(i, &alrest);
                }
                else
                    write(i, num, sizeof(buf));
            }
        }
    }