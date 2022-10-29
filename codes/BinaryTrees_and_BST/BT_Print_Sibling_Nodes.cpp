#include<iostream>

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {
        val = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
    TreeNode(int data, TreeNode* left, TreeNode* right) {
        val = data;
        this->left = left;
        this->right = right;
    }
};

TreeNode* buildtree_preOrder_boolean() {
    // root node head.
    TreeNode* root = NULL;

    // data for node value
    int data = 0;
    // lchild and rchild for left and right childrens
    std::string lchild = "false", rchild = "false";

    // Get root node data and populate in it.
    std::cin >> data;
    root = new TreeNode(data);
    // Get boolean for left child
    std::cin >> lchild;
    if (lchild == "true") {
        root->left = buildtree_preOrder_boolean();//lst
    }
    // Get boolean for right child
    std::cin >> rchild;
    if (rchild == "true") {
        root->right = buildtree_preOrder_boolean();//rst
    }

    return root;
}

void Print_Sibling_Nodes(TreeNode* root) {
    // --> base case
    if (!root) {
        return;
    }

    // --> task
    // If left child of root exist and right child is missing
    // then print the value of left node.
    if (root->left && !root->right) {
        std::cout << root->left->val << " ";
    }
    // If right child of root exist and left child is missing
    // then print the value of right node.
    else if (!root->left && root->right) {
        std::cout << root->right->val << " ";
    }

    // --> recursive case
    // Call for left and right nodes.
    Print_Sibling_Nodes(root->left);
    Print_Sibling_Nodes(root->right);
}

int main() {
    TreeNode* root = buildtree_preOrder_boolean();

    Print_Sibling_Nodes(root);
    std::cout << std::endl;

    return 0;
}
