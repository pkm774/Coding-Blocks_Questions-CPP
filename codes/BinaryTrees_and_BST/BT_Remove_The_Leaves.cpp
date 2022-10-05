#include <iostream>
#include <queue>
#include <map>

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

// Function to build simple Binary Tree using Pre-oRDER algorithm.
// Input of child nodes value will be accepted based on true and false.
TreeNode* buildtree_preOrder_boolean() {
	// root node head.
	TreeNode* root = NULL;

	// data for node value
	int data = 0;
	// lchild and rchild for left and right childrens
	std::string lchild = "false", rchild = "false";
	/* Example of preOrder_boolean input
	*
	: 10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
	*
	*/

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

TreeNode* Remove_Leaf_Nodes(TreeNode* root) {
	// --> Base Case
	if (!root) {
		return NULL;
	}

	// --> Task
	// Check if node is a leaf node then
	// delete that node and return NULL to
	// previous node.
	if (!root->left && !root->right) {
		delete root;
		return NULL;
	}

	// --> recursive case
	root->left = Remove_Leaf_Nodes(root->left);
	root->right = Remove_Leaf_Nodes(root->right);

	// Return root with removed leaf nodes
	return root;
}

// Function to print tree in pre-oRDER
void preOrderPrint(TreeNode* root) {
	// --> base case
	// When root == NULL
	if (!root) {
		return;
	}

	// --> task
	if (root->left) std::cout << root->left->val;
	else std::cout << "END";
	std::cout << " => ";
	std::cout << root->val << " ";
	std::cout << " <= ";
	if (root->right) std::cout << root->right->val;
	else std::cout << "END";
	std::cout << std::endl;

	// --> Recursive case
	preOrderPrint(root->left);
	preOrderPrint(root->right);
}

int main() {
	TreeNode* root = buildtree_preOrder_boolean();

	Remove_Leaf_Nodes(root);

	preOrderPrint(root);

	return 0;
}

/*
Problem :
Given a binary tree, remove all the leaves from the tree

Input Format :
Enter the value of the nodes of the tree

Constraints :
None

Output Format :
Display the tree in which all the leaves have been removed in pre-order traversal in the following format :
Left->data => Root->data <= Right->Data
Output END if left or right node is NULL

Sample Input :
50 true 12 true 18 false false false false

Sample Output :
12 => 50 <= END
END => 12 <= END

*/