#include <iostream>
#include <vector>
#include <map>

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

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
    TreeNode(int data, TreeNode* left, TreeNode* right)
    {
        val = data;
        this->left = left;
        this->right = right;
    }
};

// Function to build Simple Binary Tree using pre-oRDER algorithm.
// Input of root node value will be accepted until -1 get inserted.
TreeNode* buildtree_preOrder() {
    int data = 0, child = 0;
    std::cin >> data >> child; // 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

    // Create a root node and populate data
    TreeNode* root = new TreeNode(data);

    // Return root if value of child is zero
    if (child == 0) {
        return root;
    }
    else if (child == 1) {
        // Recursion call for left node only
        root->left = buildtree_preOrder(); //lst
    }
    else {
        // Recursion call for left and right nodes
        root->left = buildtree_preOrder(); //lst
        root->right = buildtree_preOrder(); //rst
    }

    // return root with left and right childrens
    return root;
}

void sum_at_level_k(TreeNode* root, int inlevel, int level, int& sum) {
    // --> base case
    // Check for NULL or
    // if Initial level is greater than current level
    if (!root || inlevel > level) {
        return;
    }

    // --> task
    // Add root value to sum if
    // Initial level is equal to current level
    if (inlevel == level) {
        sum += root->val;
    }

    // --> recursive call for left and right childrens
    sum_at_level_k(root->left, inlevel + 1, level, sum);
    sum_at_level_k(root->right, inlevel + 1, level, sum);
}

int main() {
    // Build preorder tree with number of childrens
    TreeNode* root = buildtree_preOrder();

    // Get the value of level
    int level = 0;
    std::cin >> level;

    // Sum for calculation sum of values at k level
    int sum = 0;
    sum_at_level_k(root, 0, level, sum);

    // Print total sum
    std::cout << sum << std::endl;

    return 0;
}
