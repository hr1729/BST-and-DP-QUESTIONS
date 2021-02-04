#include <iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<math.h>
#include<climits>
#define ll long long
using namespace std;
class node {
public:
	int d;
	node *l;
	node *r;
	node(int e) {
		d = e;
		l = NULL;
		r = NULL;
	}
};
node* built() {
	int d; cin >> d;
	if (d == -1) {
		return NULL;
	}
	node *x = new node(d);
	x->l = built();
	x->r = built();
	return x;
}
void print(node *root) {
	if (root == NULL) {
		return ;
	}
	cout << root->d << " ";
	print(root->l);
	print(root->r);
}





int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("ou.txt", "w", stdout);
#endif
	node *root = built();
	print(root);

}