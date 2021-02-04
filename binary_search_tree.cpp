#include <iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<deque>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<climits>
#define ll long long
using namespace std;

class node {
public:
	node *left;
	int data;
	node *right;
	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};
node *insertATnode(node *root, int data) { //inserting nodes at the tree
	if (root == NULL) {
		return new node(data);
	}
	if (data <= root->data)
		root->left = insertATnode(root->left, data);
	else if (data > root->data)
		root->right = insertATnode(root->right, data);
	return root;
}

node *build() { // building the tree
	int d;
	cin >> d;
	node *root = NULL;
	while (d != -1) {
		root = insertATnode(root, d);
		cin >> d;

	}
	return root;

}
bool search(node *root, int data) { // searching
	if (root == NULL)
		return false;
	if (root->data == data)
		return true;
	if (data <= root->data) {
		return search(root->left, data);
	}
	else {
		return search(root->right, data);
	}
}
node *deletionINBST(node *root, int data) { // deletetion
	if (root == NULL)
		return NULL;
	if (data < root->data) {
		root->left = deletionINBST(root->left, data);
		return root;
	}

	if (root->data == data) { //dletetion from here
		if (root->left != NULL and root->right == NULL) {// 1 child present
			node *temp = root->left;
			delete root;
			return temp;
		}
		else if (root->left == NULL and root->right == NULL) { //no child present
			delete root;
			return NULL;
		}
		else { // 2 child present
			node *replace = root->right;
			while (replace->left != NULL) {
				replace = replace->left;
			}
			root->data = replace->data;
			root->right = deletionINBST(root->right, replace->data);
			return root;
		}
	}
	else {
		root->right = deletionINBST(root->right, data);
		return root;
	}
}
bool isBST(node *root, int min = INT_MIN, int max = INT_MAX) { //is BST
	if (root == NULL)
		return true;
	else if (root->data >= min and root->data <= max and isBST(root->left, min, root->data) and isBST(root->right, root->data, max))
		return true;
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("ou.txt", "w", stdout);
#endif
	node *r = build();
	node *p = deletionINBST(r, 2);

}