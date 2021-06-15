#include "c_s.h"
int main()
{
    int lid, cid;
    struct sockaddr_in lidaddr, cidaddr;
    struct pool pollld[1024];
    lid = socket(AF_INET, SO_REUSEADDR, 0);
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
}