#include <iostream>

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

TreeNode* buildtree_boolean() {
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
        root->left = buildtree_boolean();//lst
    }
    // Get boolean for right child
    std::cin >> rchild;
    if (rchild == "true") {
        root->right = buildtree_boolean();//rst
    }

    return root;
}

bool Structurally_Identical(TreeNode* root1, TreeNode* root2) {
    // --> base case
    // if both trees are empty
    if (!root1 && !root2) {
        return true;
    }

    // if both trees are not empty then compare them
    if (root1 && root2) {
        return Structurally_Identical(root1->left, root2->left) &&
            Structurally_Identical(root1->right, root2->right);
    }

    // control is here means trees are not identical
    return false;
}

int main() {
    TreeNode* root1 = buildtree_boolean();
    TreeNode* root2 = buildtree_boolean();

    if (Structurally_Identical(root1, root2)) {
        std::cout << "true" << std::endl;
    }
    else {
        std::cout << "false" << std::endl;
    }

    return 0;
}
