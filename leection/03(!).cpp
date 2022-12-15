class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0,right=0;
        set<int> p;
        int maxs=0;
        while(right<s.size()){
            if(p.find(s[right])!=p.end()){
                p.erase(s[left++]);
            }else{
                p.insert(s[right++]);
                maxs=maxs>p.size()?maxs:p.size();
            }
        }
        return maxs;
    }