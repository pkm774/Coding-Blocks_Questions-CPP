#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<unordered_map>

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

// Function to create tree from inorder and preorder
TreeNode* create_tree_InPre(std::vector<int>& preorder, std::vector<int>& inorder,
	std::unordered_map<int, int>& map, int preStart, int preEnd, int inStart, int inEnd) {

	if (preStart > preEnd) {
		return nullptr;
	}

	TreeNode* root = new TreeNode(preorder[preStart]);
	int inLeft = map[root->val] - inStart;
	int inRight = inEnd - map[root->val];

	root->left = create_tree_InPre(preorder, inorder, map, preStart + 1, preStart + inLeft, inStart, inStart + inLeft - 1);
	root->right = create_tree_InPre(preorder, inorder, map, preStart + inLeft + 1, preStart + inLeft + inRight, inStart + inLeft + 1, inEnd);

	return root;
}
// base function to create from inorder and preorder
// Required: create_tree_InPre
TreeNode* from_inorder_and_preorder(std::vector<int>& preorder, std::vector<int>& inorder) {
	int preStart = 0, preEnd = preorder.size() - 1;
	int inStart = 0, inEnd = inorder.size() - 1;

	std::unordered_map<int, int> map;

	for (int i = 0; i <= inEnd; ++i) {
		map[inorder[i]] = i;
	}

	return create_tree_InPre(preorder, inorder, map, preStart, preEnd, inStart, inEnd);
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

int Count_Nodes(TreeNode* root) {
	// --> base case
	if (!root) {
		return 0;
	}

	// --> recursive case
	return 1 + Count_Nodes(root->left) + Count_Nodes(root->right);
}

// Function to check a node holds BST
// and push total number of nodes if its BST head root.
bool Check_for_bst(TreeNode* root, std::vector<int>& ans) {
	// --> base case
	if (!root) {
		return true;
	}

	// --> task
	// If the node is head root of BST
	// then calculate and push its number of nodes.
	if (checkBST(root, nullptr, nullptr)) {
		ans.push_back(Count_Nodes(root));
		return true;
	}

	// --> Recursive case
	// Check for BST in LST and RST
	Check_for_bst(root->left, ans);
	Check_for_bst(root->right, ans);

	// Return false if no BST found
	return false;
}

void Largest_BST(TreeNode* root) {
	// Vector for calculating maximum node
	std::vector<int> ans;
	// Check of BST and push number of nodes.
	Check_for_bst(root, ans);
	// If vector is not empty then print maximum value.
	if (ans.size()) {
		std::cout << *std::max_element(ans.begin(), ans.end());
	}
	std::cout << std::endl;
}

int main() {
	int size = 0;
	std::cin >> size;
	std::vector<int> preorder(size);
	for (int i = 0; i < size; ++i) {
		std::cin >> preorder[i];
	}

	std::vector<int> inorder(size);
	for (int i = 0; i < size; ++i) {
		std::cin >> inorder[i];
	}

	// Create bt from given preorder and inorder arrays
	TreeNode* root = from_inorder_and_preorder(preorder, inorder);

	// Function Call to check and print
	// largest bst in given bt.
	Largest_BST(root);

	return 0;
}
