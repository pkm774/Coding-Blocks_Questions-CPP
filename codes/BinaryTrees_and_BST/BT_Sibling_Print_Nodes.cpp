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
    if (root->left && !root->right) {
        std::cout << root->val << " ";
    }
    else if (!root->left && root->right) {
        std::cout << root->val << " ";
    }
    else if (!root->left && !root->right) {
        std::cout << root->val << " ";
    }

    // --> recursive case
    Print_Sibling_Nodes(root->left);
    Print_Sibling_Nodes(root->right);
}

void Sibling_Nodes(TreeNode* root) {
    Print_Sibling_Nodes(root->left);
    Print_Sibling_Nodes(root->right);
}

int main() {
    TreeNode* root = buildtree_preOrder_boolean();

    Sibling_Nodes(root);

    return 0;
}
