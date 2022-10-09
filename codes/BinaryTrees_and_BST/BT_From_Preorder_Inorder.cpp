#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<algorithm>
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

TreeNode* from_inorder_and_preorder(std::vector<int>& preorder,
	std::vector<int>& inorder) {
	int preStart = 0, preEnd = preorder.size() - 1;
	int inStart = 0, inEnd = inorder.size() - 1;

	std::unordered_map<int, int> map;

	for (int i = 0; i <= inEnd; ++i) {
		map[inorder[i]] = i;
	}

	return create_tree_InPre(preorder, inorder, map, preStart, preEnd, inStart, inEnd);
}

// Function to print tree in pre-oRDER
void preOrderPrint(TreeNode* root) {
	// --> base case
	// When root == nullptr
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
	int size1 = 0, size2 = 0;
	std::cin >> size1;
	std::vector<int> preorder(size1);
	for (int i = 0; i < size1; ++i) {
		std::cin >> preorder[i];
	}

	std::cin >> size2;
	std::vector<int> inorder(size2);
	for (int i = 0; i < size2; ++i) {
		std::cin >> inorder[i];
	}

	TreeNode* root = from_inorder_and_preorder(preorder, inorder);

	preOrderPrint(root);

	return 0;
}
