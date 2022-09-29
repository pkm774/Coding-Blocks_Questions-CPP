#include <iostream>
#include <vector>
#include <climits>
#include <string>

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

// Helper Function to create a BST from preorder input value
TreeNode* Insert_In_BST(TreeNode*& root, int val) {
	if (!root) {
		root = new TreeNode(val);
		return root;
	}
	else if(val <= root->val) {
		root->left = Insert_In_BST(root->left, val);
		return root;
	}
	else {
		root->right = Insert_In_BST(root->right, val);
		return root;
	}
}

// Base function to create a BST
// Required : Insert_In_BST
TreeNode* build_BST(std::vector<int>& vector) {
	TreeNode* root = NULL;

	for (int i = 0; i < vector.size(); ++i) {
		Insert_In_BST(root, vector[i]);
	}

	return root;
}

// Function to print tree in pre-oRDER
void preOrderPrint(TreeNode* root) {
	// --> base case
	// When root == NULL
	if (!root) {
		return;
	}

	// --> recursive case
	// Print root node data first
	std::cout << root->val << " ";
	// Print left child data
	preOrderPrint(root->left);
	// Print right child data
	preOrderPrint(root->right);
}

void Print_Between_keys(TreeNode* root, int k1, int k2) {
	// --> base case
	if (!root) {
		return;
	}

	// --> recursive case
	// Start Checking and printing from LST
	Print_Between_keys(root->left, k1, k2);
	// --> task
	// Check and print root->val
	if (root->val >= k1 && root->val <= k2) {
		std::cout << root->val << " ";
	}
	// then check and print from RST
	Print_Between_keys(root->right, k1, k2);
}

int main() {
	int test = 0;
	std::cin >> test;

	while (test--) {
		int size = 0;
		std::cin >> size;
		std::vector<int> vector(size);
		for (int i = 0; i < size; ++i) {
			std::cin >> vector[i];
		}

		TreeNode* root = build_BST(vector);

		// Get limits
		int k1 = 0, k2 = 0;
		std::cin >> k1 >> k2;

		std::cout << "# Preorder : ";
		preOrderPrint(root);
		std::cout << std::endl;
		std::cout << "# Nodes within range are : ";
		Print_Between_keys(root, k1, k2);
		std::cout << std::endl;
	}

	return 0;
}