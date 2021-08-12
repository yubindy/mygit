#include <iostream>
#include <algorithm>        // std::count_if
#include <vector>
#include <string>
#include <fstream>          // std::ifstream
#include <sstream>          // std::istringstream
#include <stdexcept>        // std::cerr

class StrLenIs {
private:
    int len_;

public:
    StrLenIs(int len) : len_(len) { }
    bool operator()(const std::string &str) {
        return str.length() == len_;
    }
};

int main(int argc, char *argv[]) {
    std::ifstream in("/home/zhaozeyu/Desktop/base/study/code/ggggg.txt");
    if (!in) {
        std::cerr << "无法打开输入文件" << std::endl;
        return -1;
    }
    std::vector<std::string> svec;
    std::string line;
    std::string word;
    while (getline(in, line)) {
        std::istringstream l_in(line);          // 构造字符串流，读取单词
        while (l_in >> word)
            svec.push_back(word);
    }
    const int minLen = 1;
    const int maxLen = 10;
    for (int i = minLen; i <= maxLen; ++i) {
        StrLenIs strObj(i);
        std::cout << "len : " << i << ", cnt : "
                  << std::count_if(svec.begin(),svec.end(), strObj)
                  << std::endl;
    }
    return 0;
}