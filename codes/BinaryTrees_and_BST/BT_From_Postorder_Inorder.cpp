#include<iostream>
#include<vector>
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
*                       Approach Using Unordered Hash Map O(n)
****************************************************************************************/
// Function for populating Unordered map with elements and index.
void Populate_Map(std::vector<int>& inorder, std::unordered_map<int, int>& indexMap){
	for(int i = 0; i < inorder.size(); ++i){
		indexMap[inorder[i]] = i;
	}
}

TreeNode* create_tree_InPos(std::vector<int>& postorder, std::vector<int>& inorder,
	int& postStart, int postEnd, int inStart, int inEnd, std::unordered_map<int, int>& indexMap) {

	// --> Base Case
	if (postStart < postEnd || inStart > inEnd) {
		return nullptr;
	}

	// Get postorder[postStart] element from
	// postorder vector with the help of postStart index.
	int element = postorder[postStart--];
	// Create root node from the element.
	TreeNode* root = new TreeNode(element);
	// Now get the position of that element directly
	// from the unordered hashmap with the element.
	int index = indexMap[element];

	// --> Recursive case
	// First call will be for right subtree
	root->right = create_tree_InPos(postorder, inorder, postStart, postEnd, index + 1, inEnd, indexMap);
	// Second call will be for left subtree
	root->left = create_tree_InPos(postorder, inorder, postStart, postEnd, inStart, index - 1, indexMap);

	return root;
}

TreeNode* from_inorder_and_postorder(std::vector<int>& postorder,
	std::vector<int>& inorder) {

	// Set variables for start and last index of postorder vector
	// Here poststart will be last index of postorder array i.e, size-1
	// ans postend will be the first index i.e, 0. Because
	// root element in postorder traversal is present at last.
	// So, for root element we will start from last of postorder array.
	int postStart = postorder.size() - 1, postEnd = 0;

	// Set variables for start and last index of inorder vector
	int inStart = 0, inEnd = inorder.size() - 1;

	// Unordered map for storing index acccording to
	// their corresponding elements present in inorder vector.
	std::unordered_map<int, int> indexMap;

	// Polulate the unordered map with key as vector elements
	// and value as their corresponding index.
	Populate_Map(inorder, indexMap);

	// Create Tree
	return create_tree_InPos(postorder, inorder, postStart, postEnd, inStart, inEnd, indexMap);
}

/***************************************************************************************
*                              Normal Approach O(n^2)
****************************************************************************************/

int FindPosition(std::vector<int>& inorder, int element) {
	for (int k = 0; k < inorder.size(); ++k) {
		if (inorder[k] == element)
			return k;
	}
	return -1;
}

TreeNode* Create(std::vector<int>& postorder, std::vector<int>& inorder,
	int& postStart, int postEnd, int inStart, int inEnd) {

	// --> Base Case
	if (postStart < postEnd || inStart > inEnd) {
		return nullptr;
	}

	// Get postorder[postStart] element from
	// postorder vector with the help of postStart index.
	int element = postorder[postStart--];
	// Create root node from the element.
	TreeNode* root = new TreeNode(element);
	// Now get the position of that element in inorder
	// vector and use it for dividing inorder for
	// left and right nodes.
	int position = FindPosition(inorder, element);

	// --> Recursive case
	// First call will be for right subtree
	root->right = Create(postorder, inorder, postStart, postEnd, position + 1, inEnd);
	// Second call will be for left subtree
	root->left = Create(postorder, inorder, postStart, postEnd, inStart, position - 1);

	return root;
}

TreeNode* buildTree(std::vector<int>& postorder, std::vector<int>& inorder) {
	// Set variables for start and last index of postorder vector
	// Here poststart will be last index of postorder array i.e, size-1
	// ans postend will be the first index i.e, 0. Because
	// root element in postorder traversal is present at last.
	// So, for root element we will start from last of postorder array.
	int postStart = postorder.size() - 1, postEnd = 0;

	// Set variables for start and last index of inorder vector
	int inStart = 0, inEnd = inorder.size() - 1;

	return Create(postorder, inorder, postStart, postEnd, inStart, inEnd);
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
	std::vector<int> postorder(size1);
	for (int i = 0; i < size1; ++i) {
		std::cin >> postorder[i];
	}

	std::cin >> size2;
	std::vector<int> inorder(size2);
	for (int i = 0; i < size2; ++i) {
		std::cin >> inorder[i];
	}

	// Approach using HasMap
	// TreeNode* root = from_inorder_and_postorder(postorder, inorder);

	// Normal Approach
	TreeNode* root = buildTree(postorder, inorder);

	preOrderPrint(root);

	return 0;
}
