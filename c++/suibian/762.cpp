class Solution {
public:
  int countPrimeSetBits(int left, int right) {
    int num = 0;
    std::vector<int> s{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    for (int i = left; i <= right; i++) {
      auto t = std::find(s.begin(), s.end(), __builtin_popcount(i));
      if (t != s.end())
        num++;
    }
    return num;
  }
};