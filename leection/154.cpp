#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minArray(vector<int> &numbers) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (numbers[mid] > numbers[left]) {
                right=mid;
            } else if (numbers[mid] < numbers[left]) {
                left=right+1;
            } else {
                mid--;
            }
        }
        return numbers[mid];
    }
};