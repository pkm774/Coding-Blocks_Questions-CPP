#include <iostream>

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

TreeNode* buildtree_boolean() {
    // root node head.
    TreeNode* root = NULL;

    // data for node value
    int data = 0;
    // lchild and rchild for left and right childrens
    std::string lchild = "false", rchild = "false";

    // Get root node data and populate in it.
    std::cin >> data;
    root = new TreeNode(data);
    // Get boolean for left child
    std::cin >> lchild;
    if (lchild == "true") {
        root->left = buildtree_boolean();//lst
    }
    // Get boolean for right child
    std::cin >> rchild;
    if (rchild == "true") {
        root->right = buildtree_boolean();//rst
    }

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

int sum_of_nodes(TreeNode* root) {
    // --> base case
    if (!root) {
        return 0;
    }

    return root->val + sum_of_nodes(root->left) + sum_of_nodes(root->right);
}

int main() {
    TreeNode* root = buildtree_boolean();

    std::cout << sum_of_nodes(root) << std::endl;

    return 0;
}
/*
Problem:
Given a binary tree find sum of all the nodes.

Input Format:
Enter the value of the node then the Boolean choice i.e whether the node has a left child , then enter the left child's data . The input acts in a recursive manner i.e when the left child's children are made only then we move onto the parent's right child

Constraints:
None

Output Format:
Display the sum of all the nodes

Sample Input:
50 true 25 true 12 false false false true 75 true 62 false false false

Sample Output:
224

Explanation:
If we enter the following values
50 true 25 true 12 false false false true 75 true 62 false false false

the tree would look like :
25 => 50 <= 75
12 => 25 <= END
END => 12 <= END
62 => 75 <= END
END => 62 <= END
*/
