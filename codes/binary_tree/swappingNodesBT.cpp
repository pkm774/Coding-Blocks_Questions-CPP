#include<iostream>
#include<queue>

using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* buildtree() {
	node* root = NULL;
	int data;
	cin >> data;// 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
	if (data == -1) {
		return NULL;
	}
	else {
		root = new node(data);
		root->left = buildtree();//lst
		root->right = buildtree();//rst
		return root;
	}
}

void preorderprint(node* root) {
	// base case
	if (root == NULL) {
		return;
	}

	// recursive case for printing data
	cout << root->data << " ";
	preorderprint(root->left);
	preorderprint(root->right);

}

void swap_nodes(node*& root) {
	// base case
	if (root == NULL) {
		return;
	}

	// recursive

	// swap address in current node
	swap(root->left, root->right);

	// go for left
	swap_nodes(root->left);
	// from left, go to right
	swap_nodes(root->right);
}

int main() {
	node* root = buildtree();

	cout << "Previous tree: ";
	preorderprint(root);

	swap_nodes(root);

	cout << '\n' << "After swapping nodes: ";
	preorderprint(root);

	return 0;
}
