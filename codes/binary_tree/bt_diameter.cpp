#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
private:
    int find_diameter(TreeNode *root, int &ans)
    {
        if (!root)
        {
            return 0;
        }

        int lh = find_diameter(root->left, ans);
        int rh = find_diameter(root->right, ans);

        ans = max(ans, lh + rh);

        return max(lh, rh) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int ans = 0;
        find_diameter(root, ans);
        return ans;
    }
};