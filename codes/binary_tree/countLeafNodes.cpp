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
	cin >> data;//8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
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

// global
int cnt = 0;
// function to count leaf nodes
int count_leaf_nodes(node* root) {
	// for local
	//int cnt = 0

	// for global
	cnt = 0;

	// base case
	if (root->left == NULL || root->right == NULL) {
		return ++cnt;
	}

	// recursive case
	return count_leaf_nodes(root->left) + count_leaf_nodes(root->right);
}

int main() {
	node* root = buildtree();

	cout << count_leaf_nodes(root);

	return 0;
}
