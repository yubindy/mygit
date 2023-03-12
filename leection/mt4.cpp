#include <bits/stdc++.h>
using namespace std;
vector<char> a(256,'0');
vector<char> b(256,'0');
int val;
char p;
int func() {
    if(a[255]=='F'){
        val=16;
        p='W';
    }
    if(a[255]=='F'){
        val=256;
        p='P';
    }
    return 0;
}
int main() {
    for (int i = 0; i < 256; i++) {
        cin >> a[i];
    }
    for (int j = 0; j < 256; j++) {
        cin >> a[j];
    }
    func();
    printf("%d\n", val);
    printf("%c",p);
}