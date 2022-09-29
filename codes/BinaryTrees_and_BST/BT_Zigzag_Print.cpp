#include <iostream>
#include <stack>

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

// Function for calculating height
int height(TreeNode* root)
{
	// --> base case
	// When root == NULL
	if (!root) {
		return 0;
	}

	// --> recursive case
	/* compute the height of each subtree */
	int lheight = height(root->left);
	int rheight = height(root->right);

	/* Use the largest value */
	return std::max(lheight, rheight) + 1;
}

// Helper Function to print node value at k level.
// In Decreasing order. Print only when level becomes
// zero from non zero int value.
void print_at_kLevel(TreeNode* root, int level) {
	// --> base case
	if (!root) {
		return;
	}

	// --> Task
	// Print node value if level is or becomes 0;
	if (level == 0) {
		std::cout << root->val << " ";
		return;
	}

	// --> Recursive Case
	print_at_kLevel(root->left, level - 1);
	print_at_kLevel(root->right, level - 1);
}

// Helper Function to push node value in stack at k level.
// In Decreasing order. Push only when level becomes
// zero from non zero int value.
void push_level_in_stack(std::stack<int>& stack, TreeNode* root, int level) {
	// --> base case
	if (!root) {
		return;
	}

	// --> Task
	// Push node value if level is or becomes 0;
	if (level == 0) {
		stack.push(root->val);
	}

	// --> Recursive Case
	push_level_in_stack(stack, root->left, level - 1);
	push_level_in_stack(stack, root->right, level - 1);
}

// Function to print levels in ZigZag manner.
// Required : print_at_kLevel(),push_level_in_stack()
void Print_Zig_Zag(TreeNode* root) {
	// Declare and Initialize top level as zero
	// Because tree with one node only have 0 level.
	int top_level = 0;
	// Declare and Initialize bottom level as total height.
	int bottom_level = height(root);
	
	// Iterate from 0 to height - 1;
	for (int i = top_level; i < bottom_level; ++i) {
		if (i % 2 == 0) {
			// If i is even, print the level normally.
			print_at_kLevel(root, i);
		}
		// Else first push level into the stack
		// it will be stored in reverse manner,
		// then print the stack from top.
		else {
			// Declare empty stack.
			std::stack<int> stack;
			// Push all the same level nodes into the stack.
			push_level_in_stack(stack, root, i);
			// While stack is not empty, print and pop
			while (!stack.empty()) {
				std::cout << stack.top() << " ";
				stack.pop();
			}
		}
	}
}

int main() {
	TreeNode* root = buildtree_preOrder_boolean();

	Print_Zig_Zag(root);

	return 0;
}