#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};
class Solution
{
public:
    int maxDepth(Node *root)
    {
        if (!root)
            return 0;
        int t = 0;
        for (auto i : root->children)
        {
            t = t > maxDepth(i) + 1 ? t : maxDepth(i) + 1;
        }
        return t;
    }
};