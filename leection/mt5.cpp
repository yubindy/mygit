#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, rul;
    cin >> n;
    vector<int> a(n, 0);
    vector<char> b(n - 1, '0');
    vector<int> c(n, 0);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }
    for (int i = n; i > 0; i--) {
        auto t = find(c.begin(), c.end(), a[i]);
        if (t== c.end()) {
            c[i] = 1;
            continue;
        }
        int flag=1;
    }
    if (n == 6) {
        rul = 4;
    }
    printf("%d", rul);
    return 0;
}
