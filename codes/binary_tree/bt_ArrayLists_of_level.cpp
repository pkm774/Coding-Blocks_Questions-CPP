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

void preorderprint(TreeNode* root) {
    // base case
    if (root == NULL) {
        return;
    }

    // recursive case for printing data
    std::cout << root->val << " ";
    preorderprint(root->left);
    preorderprint(root->right);

}

void create_array_list(TreeNode* root, int level, std::map<int, std::vector<int>>& map) {
    // --> base case
    if (!root) {
        return;
    }

    // Push the treenode values at a specific level
    // Key will be level and value will be
    // treenode data in the value vector.
    map[level].push_back(root->val);

    // --> recursive case
    // for left sub tree
    create_array_list(root->left, level + 1, map);
    // for right subtree
    create_array_list(root->right, level + 1, map);
}

void print_array_list(std::map<int, std::vector<int>>& map) {

    std::cout << "[";

    for (int i = 0; i < map.size(); ++i) {
        std::cout << "[";
        for (int j = 0; j < map[i].size(); ++j) {
            std::cout << map[i][j];
            if (j < map[i].size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]";
        if (i < map.size() - 1) {
            std::cout << ", ";
        }
    }

    std::cout << "]" << std::endl;
}

int main() {
    // Create binary tree
    TreeNode* root = buildtree_boolean();

    // Created an ordered map having key as int
    // and value as vector.
    std::map<int, std::vector<int>> map;

    create_array_list(root, 0, map);

    print_array_list(map);

    return 0;
}
