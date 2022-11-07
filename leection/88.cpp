#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int a = 0, b = 0, c = 0;
        vector<int> nums3(nums1);
        int t = 0;
        while (b < m || c < n) {
            if (c == n || nums2[b] < nums3[c] && b < m) {
                t = nums2[b++];
            } else if (c < n || b == m) {
                t = nums3[c++];
            }
            nums1[a++] = t;
        }
        return;
    }
};