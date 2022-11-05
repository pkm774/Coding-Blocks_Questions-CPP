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

void Tree_bottom_view(TreeNode* root, int hdistance, int level,
	std::map<int, std::pair<int, int>>& map) {

	// --> base case
	if (!root) {
		return;
	}

	// --> task
	// If current level is greater than or equal to the level
	// at current hdistance (i.e, hdistance.first),
	// store the current level with value of the node
	// with hdistance as key.
	if (level >= map[hdistance].first)
	{
		// Save root->val at level key.
		map[hdistance] = { level, root->val };
	}

	// If above 'if condition' fails, it means their is already
	// a value stored at the greater level compared to current level
	// at hdistance.

	// --> recursive case
	// Call for left child
	Tree_bottom_view(root->left, hdistance - 1, level + 1, map);
	// Call for right child
	Tree_bottom_view(root->right, hdistance + 1, level + 1, map);
}

int main() {
	// HashMap for storing distance and pair value.
	// First element 'distance' will be unique and
	// sorted as it is the key in map. Pair will hold
	// level of the node and root->val at current node.
	std::map<int, std::pair<int, int>> map;

	// Build BT by level order input
	TreeNode* root = buildtree_levelOrder();

	// Store top node elements in map
	Tree_bottom_view(root, 0, 0, map);

	// Print elements, only root->val i.e,
	// node values stored in the map.
	for (auto& it : map) {
		// it.second refers to the pair in hashmap and
		// it.second.second refers to the second value of pair
		// which contains node data.
		std::cout << it.second.second << " ";
	}

	return 0;
}

/*
ALGORITHM :
root node will be at 0 horizontal distance i.e, (hdistance = 0) and at 0 level i.e, (level = 0).
root->left will be at horizontal distance - 1 and at level + 1. (Negative indexing) (increment in level)
root->right will be at horizontal distance + 1 and at level + 1. (Positive indexing) (increment in level)

If current level is greater than or equal to the level stored at the current distance
then store or replace the current value and current level at the current dostance.
Else go for left and right child.
*/

/*

Problem :
Given a binary tree , print the nodes in left to right manner as visible from below the tree.

Input Format :
Level order input for the binary tree will be given.

Constraints :
No of nodes in the tree can be less than or equal to 10^7

Output Format :
A single line containing space separated integers representing the bottom view of the tree

Sample Input :
1 2 3 5 -1 4 -1 -1 6 -1 -1 -1 7 -1 -1

Sample Output :
5 6 7 3

*/