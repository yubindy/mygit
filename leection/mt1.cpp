#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a, maxs = 0;
    int num = 0, nums = 0, ts = 0, maxts = 0;
    cin >> a;
    vector<int> x(a, 0);
    vector<int> y(a, 0);
    for (int i = 0; i < a; i++)
        cin >> x[i];
    for (int i = 0; i < a; i++) {
        cin >> y[i];
        maxs = max(maxs, y[i]);
    }
    //     3
    // 2 1 5
    // 6 3 7
    for (int i = 0; i <= maxs; i++) {
        for (int j = 0; j < a; j++) {
            if (x[j] == i) {
                num++;
            }
        }
        if (nums < num) {
            nums = num;
            maxts = max(maxts, ts);
            ts = 1;
        } else if (nums == num) {
            ts++;
        }
        printf("%d %d %d\n", i, nums, maxts);
        for (int j = 0; j < a; j++) {
            if (y[j] == i) {
                num--;
            }
        }
    }
    maxts = max(maxts, ts);
    printf("%d %d", nums, maxts);
    return 0;
}
