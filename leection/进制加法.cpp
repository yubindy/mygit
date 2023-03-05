#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    char getChar(int n) {
        if (n <= 9)
            return n + '0';
        else if (n <= 35) {
            return n - 10 + 'a';
        } else {
            return n - 36 + 'A';
        }
    }
    //区分下大小写，这里还有对于 "A ~Z"的处理
    int getInt(char ch) {
        if ('0' <= ch && ch <= '9')
            return ch - '0';
        else if (ch <= 'a') {
            return ch - 'a' + 10;
        } else {
            return ch - 'A' + 36;
        }
    }
    string add36Strings(string num1, string num2) {
        int carry = 0;
        int i = num1.size() - 1, j = num2.size() - 1;
        string res;
        while (i >= 0 || j >= 0 || carry) {
            int x = i >= 0 ? getInt(num1[i]) : 0;
            int y = j >= 0 ? getInt(num2[j]) : 0;
            int temp = x + y + carry;
            res += getChar(temp % 62);
            carry = temp / 62;
            i--, j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
//我使用了getChar(int n)和getInt(char ch)两个辅助函数来完成62进制字符与数值的转换。
int main() {
    Solution s;
    string a = "1b", b = "2x", c;
    c = s.add36Strings(a, b);
    cout << c << endl;
}