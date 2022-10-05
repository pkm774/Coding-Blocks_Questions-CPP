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

TreeNode* Create_Inorder_BST(std::vector<int>& arr, int start, int end) {
	// --> base case
	if (start > end) {
		return NULL;
	}

	// --> task
	int mid = (start + end) / 2;
	// Create node with mid value.
	TreeNode* root = new TreeNode(arr[mid]);
	// Start to index before mid passed for left sub-tree.
	root->left= Create_Inorder_BST(arr, start, mid - 1);
	// Index after mid to end passed for right sub-tree.
	root->right = Create_Inorder_BST(arr, mid + 1, end);

	// Return Root value.
	return root;
}

TreeNode* Inorder_BST(std::vector<int>& arr) {
	int start = 0;
	int end = arr.size() - 1;

	return Create_Inorder_BST(arr, start, end);
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
	sum += root->val;
	root->val = sum;
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

	// --> recursive case
	// Print root node data first
	std::cout << root->val << " ";
	// Print left child data
	preOrderPrint(root->left);
	// Print right child data
	preOrderPrint(root->right);
}

int main() {
	int size = 0;
	std::cin >> size;

	// Input Inorder or Sorted array
	std::vector<int> arr(size);
	for (int i = 0; i < size; ++i) {
		std::cin >> arr[i];
	}

	// Create BST from inorder input
	TreeNode* root = Inorder_BST(arr);

	// Covert BST to larger sum BST
	int sum = 0;
	Sum_of_greater_nodes(root, sum);

	// Print BST with pre-order traversal.
	preOrderPrint(root);

	return 0;
}
