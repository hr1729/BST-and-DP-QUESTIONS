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
#include<cmath>
using namespace std;

class node {
public:
	vector<int> v;
	void init(int d) { //using maximum nodes formulae 4*n in a tree
		v.resize(4 * d, 0);
	}
	void build(int a[], int start, int end, int node) { // building the tree
		if (start == end) {
			v[node] = a[start];
			return;
		}
		int mid = (start + end) / 2;
		build(a, start, mid, 2 * node + 1);
		build(a, mid + 1, end, 2 * node + 2);
		v[node] = v[2 * node + 1] + v[2 * node + 2];
	}
	int query(int start, int end, int l , int r, int node) {
		if (l > end or r < start) //no overlap
			return 0;
		if (start >= l and end <= r) //partial overlap
			return v[node];
		int mid = (start + end) / 2;
		int left = query(start, mid, l, r, 2 * node + 1);
		int right = query(mid + 1, end, l, r, 2 * node + 2);
		return left + right;

	}
	void update(int a[], int start, int end, int up, int k, int node) {
		if (start == end) {
			if (up == start)
				v[node] = k;
			else {
				v[node] = a[start];
			}
			return ;
		}
		int mid = (start + end) / 2;
		update(a, start, mid, up, k, 2 * node + 1);
		update(a, mid + 1, end, up, k, 2 * node + 2);
		v[node] = v[2 * node + 1] + v[2 * node + 2];
	}


};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("ou.txt", "w", stdout);
#endif
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	node tree;
	tree.init(n);
	tree.build(a, 0, n - 1, 0);
	tree.update(a, 0, n - 1, 2, 5, 0);
	for (int i = 0; i < 4 * n; i++)
		cout << tree.v[i] << " ";
	cout << endl;
	cout << tree.query(0, n - 1, 1, 3, 0);

}
