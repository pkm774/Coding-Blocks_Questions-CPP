#include <iostream>
#include <queue>
#include <map>

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

void Tree_top_view(TreeNode* root, int level,
	std::map<int, int>& map) {

	// --> base case
	if (!root) {
		return;
	}

	// --> task
	// If value at level does not exist (equal to end)
	// store val at level key. If value at level exist
	// then it will not be equal to map.end().
	if (map.find(level) == map.end())
	{
		// Save root->val at level key.
		map[level] = root->val;
	}

	// --> recursive case
	// Call for left child
	Tree_top_view(root->left, level - 1, map);
	// Call for right child
	Tree_top_view(root->right, level + 1, map);
}

int main() {
	// Initial map for storing level and node value.
	// First element 'level' will be unique and
	// sorted as it is the key in map, root->val will be
	// the second element of map stored according to key(level);
	std::map<int, int> map;

	// Build BT by level order input
	TreeNode* root = buildtree_levelOrder();

	// Store top node elements in map
	Tree_top_view(root, 0, map);

	// Print elements, only root->val
	for (auto& it : map) {
		std::cout << it.second << " ";
	}

	return 0;
}

// ALGORITHM :
/*
root node at level 0 will be at 0 position.
root->left at level 1 will be at -1 position.
root->right at level 1 will be at 1 position.
*/

/*
Problem :
Given a binary tree , print the nodes in left to right manner as visible from above the tree

Input Format :
Level order input for the binary tree will be given.

Constraints :
No of nodes in the tree can be less than or equal to 10^7

Output Format :
A single line containing space separated integers representing the top view of the tree

Sample Input :
1 2 3 4 5 6 -1 -1 -1 -1 -1 -1 -1

Sample Output :
4 2 1 3

*/
