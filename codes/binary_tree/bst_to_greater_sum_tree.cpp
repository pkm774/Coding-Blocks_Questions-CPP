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
    void gst(TreeNode* root, int &sum){
        // --> base case
        if(!root){
            return;
        }

        // --> recursive case
        gst(root->right, sum);
        root->val = sum + root->val;
        sum = root->val;
        gst(root->left, sum);
    }

public:
    TreeNode *bstToGst(TreeNode *root)
    {
        int sum = 0;
        gst(root, sum);
        return root;
    }
};