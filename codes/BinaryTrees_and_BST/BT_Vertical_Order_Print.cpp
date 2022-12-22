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
TreeNode* buildtree_levelOrder(int& level) {
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

void Tree_top_view(TreeNode* root, int distance,
	std::map<int, std::vector<int>>& map) {

	// --> base case
	if (!root) {
		return;
	}

	// --> task
	// Save root->val inside vector at level key.
	map[distance].push_back(root->val);

	// --> recursive case
	// Call for left child
	Tree_top_view(root->left, distance - 1, map);
	// Call for right child
	Tree_top_view(root->right, distance + 1, map);
}

int main() {
	int tlevel = 0;
	std::cin >> tlevel;
	// Initial map for storing distance and node value.
	// First element 'distance' will be unique and
	// sorted as it is the key in map, root->val will be
	// the second element of map stored according to key(level);
	std::map<int, std::vector<int>> map;

	// Build BT by level order input
	TreeNode* root = buildtree_levelOrder(tlevel);

	// Store top node elements in map
	Tree_top_view(root, 0, map);

	// Print vectors from map 
	std::map<int, std::vector<int>> ::iterator it;
	for (it = map.begin(); it != map.end(); ++it) {
		for (int i = 0; i < it->second.size(); ++i) {
			std::cout << it->second[i] << " ";
		}
	}

	return 0;
}

// ALGORITHM :
/*
root node will be at 0 distance.
root->left will be at -1 distance.
root->right will be at 1 distance.
*/

/*
Problem :
You will be given a Binary Tree. Your task is to print
the binary tree in Vertical Fashion. The image below describes
how we define a vertical traversal of a tree.

Input Format :
You will be given an Integer N denoting the number of levels
in the corresponding tree. On the next line you will be
given (2^N)-1 order integers denoting the level order input
for the tree. If at any level any node is absent then that will
denoted by -1 and every integer other than -1 shows the presence
of a node at that level.

Constraints :
1 <= N <= 10^5

Output Format :
Print all nodes of a given column in the same line.

Sample Input :
4
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 8 -1 9 -1 -1 -1 -1

Sample Output :
4 2 1 5 6 3 8 7 9

Explanation :
Refer to the image.
We are to simply print the traversal of each
vertical level from left to right , using pre order traversal.
{4} {2} {1 5 6} {3 8} {7} {9}

*/