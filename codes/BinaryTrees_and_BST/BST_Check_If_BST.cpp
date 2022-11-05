#include<iostream>

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode() {
		val = 0;
		left = nullptr;
		right = nullptr;
	}
	TreeNode(int data) {
		val = data;
		left = nullptr;
		right = nullptr;
	}
	TreeNode(int data, TreeNode* left, TreeNode* right) {
		val = data;
		this->left = left;
		this->right = right;
	}
};

// Function to build Simple Binary Tree using pre-oRDER algorithm.
// Input of root node value will be accepted until -1 get inserted.
TreeNode *buildtree_preOrder()
{
	int data = 0;
	std::cin >> data; // 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 (Not BST)
                      // 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1 (BST)

	// Terminate in case of -1
	if (data == -1)
	{
		return NULL;
	}

	// Create a root node and populate data
	TreeNode *root = new TreeNode(data);
	// Recursion call for left and right nodes
	root->left = buildtree_preOrder();	// lst
	root->right = buildtree_preOrder(); // rst

	return root;
}

// The idea is to use pointers instead of int
// because nullptr turns to be 0 when compared.
bool checkBST(TreeNode *root, int *min, int *max)
{
	// --> Base Case
	if (!root) {
		return true;
	}

	// If min node exist (left child) and
	// it's value is greater than root node
	// then return false.
	if (min && root->val <= *min){
		return false;
	}

	// If max node exist (right child) and
	// it's value is smaller than root node
	// then return false.
	if (max && root->val >= *max){
		return false;
	}

	// Check for both lST ans RST
	// For LST, we will pass root->left as root node,
	// min as minimum value for LST, address of root->val as
	// maximum value for LST.
	return checkBST(root->left, min, &(root->val))
	// For RST, we will pass root->right as root node,
	// address of root->val as minimum value for RST,
	// and max as maximum value for RST.
	&& checkBST(root->right, &(root->val), max);
}

int main() {
	// Create bt from given preorder input
	TreeNode* root = buildtree_preOrder();

	// Function Call to check if tree is
    // BST or not.
    checkBST(root, nullptr, nullptr) ? std::cout << "True" : std::cout << "False";
    std::cout << std::endl;

	return 0;
}
