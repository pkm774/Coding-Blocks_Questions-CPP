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

// Function to print node->values at k level from the given node.
// Here node->val is pushed instead of printing.
void push_at_klevel(TreeNode* root, int kdistance, std::vector<int>& ans) {
	// --> base case
	// If node doesn't exist or kdistance becomes less than 0
	// (i.e, downward level becomes 0) return to function call
	if (!root || kdistance < 0) {
		return;
	}

	// --> task
	// Push the node->val into
	// vector when kdistance becomes 0 (at level 0).
	if (kdistance == 0) {
		ans.push_back(root->val);
		return;
	}

	// --> recursive case
	// Decrease kdistance (i.e, level )
	// for getting elements of 0th level.
	push_at_klevel(root->left, kdistance - 1, ans);
	push_at_klevel(root->right, kdistance - 1, ans);
}

int find_and_print_kTHnodes(TreeNode* root, int targetnode, int kdistance, std::vector<int>& ans) {
	// --> base case
	// when root is null we will
	// return invalid data i.e, -1.
	if (!root) {
		return -1;
	}

	// --> task
	// If node val matches the given target i.e,
	// targetnode then call the push_at_klevel() function
	// to push the node in vector and return 0
	// to show that node matching target node exist
	// and have been pushed in vector.
	if (root->val == targetnode) {
		push_at_klevel(root, kdistance, ans);
		return 0;
	}

	// If root->val doesn't matches with targetnode then
	// search for node matching with targetnode in LST.
	// If node matching targetnode exist in LST
	// then leftdistance will hold 0.
	int leftdistance = find_and_print_kTHnodes(root->left, targetnode, kdistance, ans);
	// If node exist then :
	if (leftdistance != -1) {
		// leftdistance will be holding 0.
		// if leftdistance + 1 becomes equal to kdistance
		// then pushback current root->val into vector.
		if (leftdistance + 1 == kdistance) {
			ans.push_back(root->val);
		}
		// else call push_at_klevel() for RST.
		else {
			push_at_klevel(root->right, kdistance - leftdistance - 2, ans);
		}

		// Return
		return leftdistance + 1;
	}

	// If root->val doesn't matches with targetnode and
	// no matching node exist in LST then search for node
	// matching with targetnode in RST. If node matching
	// targetnode exist in RST then rightdistance will hold 0.
	int rightdistance = find_and_print_kTHnodes(root->right, targetnode, kdistance, ans);
	// If node exist then :
	if (rightdistance != -1) {
		// Same as leftdistance, rightdistance will be holding 0.
		// if rightdistance + 1 becomes equal to kdistance
		// then pushback current root->val into vector.
		if (rightdistance + 1 == kdistance) {
			ans.push_back(root->val);
		}
		// else call push_at_klevel() for LST.
		else {
			push_at_klevel(root->left, kdistance - rightdistance - 2, ans);
		}

		// Return
		return rightdistance + 1;
	}

	// If node not found then return -1
	return -1;
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

	TreeNode* root = from_inorder_and_preorder(preorder, inorder);

	int test = 0;
	std::cin >> test;

	while (test--) {
		int targetnode = 0, kdistance = 0;
		std::cin >> targetnode >> kdistance;

		std::vector<int> ans;
		find_and_print_kTHnodes(root, targetnode, kdistance, ans);

		if (ans.size()) {
			std::sort(ans.begin(), ans.end());
			for (int i = 0; i < ans.size(); ++i) {
				std::cout << ans[i] << " ";
			}
		}
		else {
			std::cout << 0;
		}
		std::cout << std::endl;
	}

	return 0;
}
