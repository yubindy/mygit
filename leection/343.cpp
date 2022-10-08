#include <string>
#include <string_view>
int main() {
    std::string_view pt("123456");
    std::stirng pp(pt);
    printf("view:%d true:%d", pt, pp);
    pp[3] = '9';
    printf("view:%d true:%d", pt, pp);
    return 0;
}