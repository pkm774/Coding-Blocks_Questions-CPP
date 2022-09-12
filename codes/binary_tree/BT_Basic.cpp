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

void inorderprint(node* root) {
	// base case
	if (root == NULL) {
		return;
	}

	// recursive case for printing data
	inorderprint(root->left);
	cout << root->data << " ";
	inorderprint(root->right);

}

void postorderprint(node* root) {
	// base case
	if (root == NULL) {
		return;
	}

	// recursive case for printing data
	postorderprint(root->left);
	postorderprint(root->right);
	cout << root->data << " ";

}

int main() {
	node* root = buildtree();

	preorderprint(root);
  cout<<'\n';
	inorderprint(root);
  cout<<'\n';
  postorderprint(root);

	return 0;
}
