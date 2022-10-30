#include <iostream>
#include <string>
#include <string_view>

int main() {
    std::string cstr("yangxunwu");
    std::string_view stringView1(cstr.data());
    std::string_view stringView2;
    std::cout << "stringView1: " << stringView1
              << ", size view1 " << sizeof(stringView1)
              << "stringView2" << stringView2
              << ", size view2 " << sizeof(stringView2) << std::endl;
    return 0;
}