#include<iostream>
#include<queue>

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

	return 0;
}
