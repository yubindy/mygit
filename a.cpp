// 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
// B是A的子结构， 即A中有出现和B相同的结构和节点值

#include <cstddef>
#include <stdio.h>
#include <stdlib.h>

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
// 本题面试官已设置测试用例
// 请根据题目要求确定返回值类型和参数列表(输入)
int solution(char *str, char t, char ***p) {
    int i = 0;
    *p = (char **)malloc(sizeof(char **));
    char *s = std::strtok(str, &t);
    cout << s << " " << sizeof(s) << endl;
    *p[i] = (char *)malloc(sizeof(s));
    memcpy(*p[i], s, sizeof(s));
    while (s != NULL) {
        s = std::strtok(NULL, &t);
        if (s == NULL) {
            break;
        }
        cout << s << " " << sizeof(*s) << endl;
        *p[i] = (char *)malloc(sizeof(s));
        memcpy(*p[i], s, sizeof(s));
        i++;
    }
    return i;
}

int main() {
    char str[128] = ",Hello,World!,dede";
    char t = ',';
    char **p = NULL;
    cout << solution(str, t, &p) << endl;
    cout << p[0] << " " << p[1] << endl;
    free(p);
}