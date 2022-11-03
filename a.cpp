#include <bits/stdc++.h>
using namespace std;

int main() {
    std::string a("12345");
    char *b = a.data();
    size_t c = 1000000;
    std::memcpy(b + a.size(), (char *)(&c), sizeof(c));
    printf("%s\n", b);
    printf("%s\n", b + a.size());
    printf("hhh- %d", *(size_t *)(b + a.size()));
    return 0;
}