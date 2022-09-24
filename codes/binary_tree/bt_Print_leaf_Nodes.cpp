#include <iostream>
#include <queue>

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

TreeNode* buildtree_levelOrder() {
    // Create new root node
    TreeNode* root = NULL;

    // data for node value
    int data = 0;
    std::cin >> data;

    if (data == -1) {
        return NULL;
    }
    else {
        // Queue
        std::queue<TreeNode*> queue;

        // Populate root nodde with the data.
        root = new TreeNode(data);

        // Push root element inside queue.
        queue.push(root);

        while (!queue.empty()) {
            TreeNode* front = queue.front();
            queue.pop();

            // Left child and right child data.
            int lchild = 0, rchild = 0;
            // Input lchild and rchild;
            std::cin >> lchild >> rchild;

            // Check -1 for lchild
            if (lchild != -1) {
                front->left = new TreeNode(lchild);
                queue.push(front->left);
            }

            // Check -1 for rchild
            if (rchild != -1) {
                front->right = new TreeNode(rchild);
                queue.push(front->right);
            }
        }
    }
    return root;
}

void print_leafNodes(TreeNode* root) {
    // base case
    if (root->left == NULL && root->right==NULL) {
        std::cout << root->val << " ";
        return;
    }

    print_leafNodes(root->left);
    print_leafNodes(root->right);
}

int main() {
    // Create binary tree
    TreeNode* root = buildtree_levelOrder();

    // Print and check
    print_leafNodes(root);

    return 0;
}
