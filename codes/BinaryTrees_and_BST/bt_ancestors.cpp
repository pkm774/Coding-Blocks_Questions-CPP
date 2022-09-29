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

// Brute Force
class Solution
{
private:
    vector<int> a;

    bool path(TreeNode *root, TreeNode *Q)
    {
        // --> base case
        if (root == NULL)
        {
            return false;
        }
        if (root == Q)
        {
            a.push_back(root->val);
            return true;
        }

        a.push_back(root->val);

        bool left = path(root->left, Q);
        bool right = path(root->right, Q);

        if (left == false and right == false)
        {
            a.pop_back();
        }

        return (left || right);
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        path(root, q);
        path(root, p);
        return NULL;
    }
};

// Optimized
class Solution2
{
private:
    TreeNode *lca(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root == p || root == q)
        {
            return root;
        }

        TreeNode *l1 = lca(root->left, p, q);
        TreeNode *r1 = lca(root->right, p, q);

        if (l1 && r1)
        {
            return root;
        }

        return l1 == NULL ? r1 : l1;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        lca(root, p, q);
    }
};