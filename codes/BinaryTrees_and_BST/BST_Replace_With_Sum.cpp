#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<algorithm>

/*-----------------------------------------------------------------------
							TREE-NODE DEFINATION
------------------------------------------------------------------------*/

class TreeNode {
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
	else if (val <= root->val) {
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

void Sum_of_greater_nodes(TreeNode* root, int& sum) {
	// --> base case
	if (!root) {
		return;
	}

	// --> recursive case
	// Call for right subtree because it will have the
	// greatest element and start adding from their.
	Sum_of_greater_nodes(root->right, sum);
	// --> task
	// Add node value to sum then modify node value with sum.
	int temp = root->val;
	root->val = sum;
	sum += temp;
	// Call for left subtree because.
	Sum_of_greater_nodes(root->left, sum);
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
	std::cout << root->val;
	std::cout << " <= ";
	if (root->right) std::cout << root->right->val;
	else std::cout << "END";
	std::cout << std::endl;

	// --> Recursive case
	preOrderPrint(root->left);
	preOrderPrint(root->right);
}

int main() {
	int size = 0;
	std::cin >> size;

	// Input Preorder, Inorder or Sorted array
	std::vector<int> arr(size);
	for (int i = 0; i < size; ++i) {
		std::cin >> arr[i];
	}

	// Create BST from inorder input
	TreeNode* root = build_BST(arr);

	// Covert BST to larger sum BST
	int sum = 0;
	Sum_of_greater_nodes(root, sum);

	// Print BST with pre-order traversal.
	preOrderPrint(root);

	return 0;
}
