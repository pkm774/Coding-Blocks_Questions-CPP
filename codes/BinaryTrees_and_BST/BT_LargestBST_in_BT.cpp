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

bool Is_BST(TreeNode* root) {
	// --> base case
	if (!root) {
		return true;
	}

	// --> task
	// Check for left child node
	if ((root->left) && (root->left->val > root->val)) {
		return false;
	}
	// Check for right child node
	if ((root->right) && (root->right->val < root->val)) {
		return false;
	}

	// --> recursive case
	// Check for LST and RST
	if (!Is_BST(root->left) || !Is_BST(root->right)) {
		return false;
	}

	// Return true if above condition fails.
	return true;
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
	if (Is_BST(root)) {
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
