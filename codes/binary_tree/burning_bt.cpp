#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        val = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
    TreeNode(int data, TreeNode *left, TreeNode *right)
    {
        val = data;
        this->left = left;
        this->right = right;
    }
};

class Solution
{
private:
    vector<TreeNode *> path;
    bool dfs(TreeNode *root, int target)
    {
        if (!root)
        {
            return false;
        }

        if (root->val == target)
        {
            path.push_back(root);
            return true;
        }

        path.push_back(root);
        bool left = dfs(root->left, target);
        bool right = dfs(root->right, target);

        if (left == false && right == false)
        {
            path.pop_back();
        }

        return (left || right);
    }

    int height(TreeNode *root, TreeNode *blocked)
    {
        // --> basecase
        if (!root || root == blocked)
        {
            return 0;
        }

        // --> recursive case
        int lefth = height(root->left, blocked);
        int righth = height(root->right, blocked);

        return max(lefth, righth) + 1;
    }

public:
    int minTime(TreeNode *root, int target)
    {
        dfs(root, target);
        reverse(path.begin(), path.end());

        int ans = 0;

        for (int i = 0; i < path.size(); ++i)
        {
            if (i - 1 >= 0)
            {
                ans = max(ans, (i - 1 + height(path[i], path[i - 1])));
            }
            else
            {
                ans = max(ans, (i - 1 + height(path[i], NULL)));
            }
        }

        return ans;
    }
};