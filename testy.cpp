#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int left = 0, right = arr.size() - 1;
        int mid;
        while (right > left)
        {
            mid = (left + right) / 2;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return mid; 
            else if (arr[mid] > arr[mid - 1])
                left = mid;
            else if (arr[mid] > arr[mid + 1])
                right = mid;
        }
        return 0;
    }
};
int main()
{
    Solution val;
    vector<int> s{24,69,100,99,79,78,67,36,26,19};
    int t=val.peakIndexInMountainArray(s);
    return 0;
}
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> stack;
        while (root != nullptr || stack.size() > 0) {
            while (root != nullptr) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            --k;
            if (k == 0) {
                break;
            }
            root = root->right;
        }
        return root->val;
    }
};