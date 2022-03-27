#include <stdio.h>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> missingRolls(vector<int> &rolls, int mean, int n) {
    
    int size=rolls.size();
    int sum = mean * (size + n);
    vector<int> returns;
    for (auto &it : rolls) {
      sum -= it;
    }
    if (sum < n || sum > 6 * n)
      return returns;
    int t = sum / n;
    while (n--) {
      sum -= t;
      returns.push_back(t);
      if(n!=0)
      t = sum / n;
    }
    return returns;
  }
};
int main() {
  Solution t;
  vector<int> rolls{3,2,4,3};
  int mean = 4;
  int n = 2;
  auto s = t.missingRolls(rolls, mean, n);
  for (auto it : s) {
    printf("%d", it);
  }
  return 0;
}