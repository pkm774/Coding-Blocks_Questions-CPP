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

void create_array_list(TreeNode* root, int level,
	std::map<int, std::vector<int>>& map) {

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

    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }
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

/*
Problem :
Given a binary tree. Print the level order traversal, make sure each level start at a new line.

Input Format :
Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL

Constraints :
None

Output Format :
Print the level order in which the different levels are in different lines, all the values should be in a space separated manner

Sample Input :
10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false

Sample Output :
10
20 30
40 50 60 73

*/
