/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* build_bst(vector<int>& preorder, int& pre_index, val) {
        // --> base case
        if(pre_index == preorder.size() || preorder[pre_index] > val){
            return NULL;
        }

        // --> task
        TreeNode* root = new TreeNode(preorder[pre_index++]);

        // --> recursive case
        root->left = build_bst(preorder, pre_index, root->val);
        root->right = build_bst(preorder, pre_index, val);

        // --> return root with left and right childrens
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int pre_index = 0, val = INT_MAX;
        return build_bst(preorder, pre_index, val)
    }
};
