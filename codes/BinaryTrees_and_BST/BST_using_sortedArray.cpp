#include <iostream>
#include <vector>

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode()
    {
        val = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
    TreeNode(int data, TreeNode* left, TreeNode* right)
    {
        val = data;
        this->left = left;
        this->right = right;
    }
};

TreeNode* build_BST(std::vector<int>& arr, int start, int end) {
    // --> base case
    if (start > end) {
        return NULL;
    }

    // --> recursive case
    // Find Mid
    int mid = (start + end) / 2;
    // Create root node
    TreeNode* root = new TreeNode(arr[mid]);
    // Create left sub tree
    root->left = build_BST(arr, start, mid - 1);
    // Create right sub tree
    root->right = build_BST(arr, mid + 1, end);

    // Return root node
    return root;
}

void preorderprint(TreeNode* root) {
    // base case
    if (root == NULL) {
        return;
    }

    // recursive case for printing data
    std::cout << root->val << " ";
    preorderprint(root->left);
    preorderprint(root->right);
}

void sortedArray_to_BST(std::vector<int>& arr) {
    // Start and end of the vector.
    int start = 0;
    int end = arr.size() - 1;

    // Create and get root head of the BST.
    TreeNode* root = build_BST(arr, start, end);

    // Print BST in preorder form.
    preorderprint(root);
    std::cout << std::endl;
}

int main() {
	int test = 0;
	std::cin >> test;

	while (test--) {
		int size = 0;
		std::cin >> size;

		std::vector<int> arr(size);
		for (int i = 0; i < size; ++i) {
			std::cin >> arr[i];
		}

		sortedArray_to_BST(arr);
	}

	return 0;
}
