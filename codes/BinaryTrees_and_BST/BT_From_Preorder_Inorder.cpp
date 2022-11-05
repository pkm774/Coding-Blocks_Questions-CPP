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


/***************************************************************************************
*                               Approach Using Hash Map
****************************************************************************************/

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

/***************************************************************************************
*                                Normal Approach
****************************************************************************************/

int FindPosition(std::vector<int>& inorder, int element) {
	for (int k = 0; k < inorder.size(); ++k) {
		if (inorder[k] == element)
			return k;
	}
	return -1;
}

TreeNode* Create(std::vector<int>& preorder, std::vector<int>& inorder,
	int& preStart, int preEnd, int inStart, int inEnd) {

	// --> Base Case
	if (preStart > preEnd || inStart > inEnd) {
		return nullptr;
	}

	// Get preorder[preStart] element from
	// preorder vector with the help of preStart index
	int element = preorder[preStart++];
	// Create root node from that element.
	TreeNode* root = new TreeNode(element);
	// Now get the position of that element in inorder
	// vector and use it for dividing inorder for
	// left and right nodes.
	int position = FindPosition(inorder, element);

	// --> Recursive case
	root->left = Create(preorder, inorder, preStart, preEnd, inStart, position - 1);
	root->right = Create(preorder, inorder, preStart, preEnd, position + 1, inEnd);

	return root;
}

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
	// Set variables for start and last index of preorder vector
	int preStart = 0, preEnd = preorder.size() - 1;

	// Set variables for start and last index of inorder vector
	int inStart = 0, inEnd = inorder.size() - 1;

	return Create(preorder, inorder, preStart, preEnd, inStart, inEnd);
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

	// Approach using HasMap
	// TreeNode* root = from_inorder_and_preorder(preorder, inorder);

	// Normal Approach
	TreeNode* root = buildTree(preorder, inorder);

	preOrderPrint(root);

	return 0;
}
