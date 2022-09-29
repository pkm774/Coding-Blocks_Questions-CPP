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

/*-----------------------------------------------------------------------
					BT & BST-Utility functions
------------------------------------------------------------------------*/

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

/*-----------------------------------------------------------------------
						 BT & BST-Input Functions
------------------------------------------------------------------------*/

// Function to build Simple Binary Tree using pre-oRDER algorithm.
// Input of root node value will be accepted until -1 get inserted.
TreeNode* buildtree_preOrder() {
	int data = 0;
	std::cin >> data; // 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

	// Terminate in case of -1
	if (data == -1) {
		return NULL;
	}

	// Create a root node and populate data
	TreeNode* root = new TreeNode(data);
	// Recursion call for left and right nodes
	root->left = buildtree_preOrder(); //lst
	root->right = buildtree_preOrder(); //rst

	return root;
}

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

// Function to build simple Binary Tree using leve-oRDER algorithm.
// Input of root node value will be accepted until -1 get inserted.
TreeNode* buildtree_levelOrder() {
	// Create new root node
	TreeNode* root = NULL;

	// data for node value
	int data = 0;
	std::cin >> data;

	/* Example of level_oRDER input
	*
	1
	2 3
	4 5
	6 7
	-1 -1
	-1 -1
	-1 -1
	-1 -1
	*
	*/

	// If data is -1 means no root node and return NULL.
	if (data == -1) {
		return root;
	}
	else {
		// Queue for level order value pushing.
		std::queue<TreeNode*> queue;

		// Populate root node with the data.
		root = new TreeNode(data);

		// Push root element inside queue.
		queue.push(root);

		// Check until the queue become empty,
		// means left and right have been populated with values.
		while (!queue.empty()) {
			// Save root node data in front node
			TreeNode* front = queue.front();

			// Empty queue for left child and right child
			queue.pop();

			// Left child and right child data.
			int lchild = 0, rchild = 0;
			// Input lchild and rchild;
			std::cin >> lchild >> rchild;

			// Check -1 in input for lchild
			if (lchild != -1) {
				front->left = new TreeNode(lchild);
				queue.push(front->left);
			}

			// Check -1 in input for rchild
			if (rchild != -1) {
				front->right = new TreeNode(rchild);
				queue.push(front->right);
			}
		}
	}
	return root;
}

//--------------------------------------------------------------------------
// Functions to build Binary Search Tree from given integer array.
// 1. build_BST()  ,  2. Insert_In_BST()

// Helper Function to create a BST from preorder input value
TreeNode* Insert_In_BST(TreeNode*& root, int val) {
	if (!root) {
		root = new TreeNode(val);
	}
	else if (val <= root->val) {
		root->left = Insert_In_BST(root->left, val);
	}
	else {
		root->right = Insert_In_BST(root->right, val);
	}

	return root;
}
// Base function to create a BST
// Required : Insert_In_BST()
TreeNode* build_BST(std::vector<int>& vector) {
	TreeNode* root = NULL;

	for (int i = 0; i < vector.size(); ++i) {
		Insert_In_BST(root, vector[i]);
	}

	return root;
}
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// Functions to Print level wise in zigZag order.
// 1. Print_Zig_Zag()  ,  2. print_at_kLevel()  ,   3. push_level_in_stack()

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
//--------------------------------------------------------------------------



/*-----------------------------------------------------------------------
					BT & BST-Output & print Functions
------------------------------------------------------------------------*/

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

// Function to print tree in in-oRDER
void inOrderPrint(TreeNode* root) {
	// --> base case
	// When root == NULL
	if (!root) {
		return;
	}

	// --> recursive case
	// Print left child data first
	inOrderPrint(root->left);
	// Print root node data
	std::cout << root->val << " ";
	// Print right child data
	inOrderPrint(root->right);
}

// Function to print tree in post-oRDER
void postOrderPrint(TreeNode* root) {
	// --> base case
	// When root == NULL
	if (!root) {
		return;
	}

	// --> recursive case
	// Print left child data first
	postOrderPrint(root->left);
	// Print right child data
	postOrderPrint(root->right);
	// Print root node data
	std::cout << root->val << " ";
}

// Function to print tree in diagram
void prettyPrintTree(TreeNode* node, std::string prefix = "", bool isLeft = true) {
	if (node == nullptr) {
		std::cout << "Empty tree";
		return;
	}

	if (node->right) {
		prettyPrintTree(node->right, prefix + (isLeft ? "|   " : "    "), false);
	}

	std::cout << prefix + (isLeft ? "|... " : "|''' ") + std::to_string(node->val) + "\n";

	if (node->left) {
		prettyPrintTree(node->left, prefix + (isLeft ? "    " : "|   "), true);
	}
}

/*-----------------------------------------------------------------------
							Main Driver
------------------------------------------------------------------------*/

int main() {
	// Create Simple Binary Tree using pre-oRDER method
	// and point it to root1 Node
	TreeNode* root1 = buildtree_preOrder();

	// Pre-Order Printing of root1 tree.
	preOrderPrint(root1);
	std::cout << std::endl;

	// In-Order Printing of root1 tree.
	inOrderPrint(root1);
	std::cout << std::endl;

	// Post-Order Printing of root1 tree.
	postOrderPrint(root1);
	std::cout << std::endl;

	// Create Simple Binary Tree using level-oRDER method
	// and point it to root2 Node
	TreeNode* root2 = buildtree_levelOrder();
	std::cout << std::endl;
	prettyPrintTree(root2);

	return 0;
}
