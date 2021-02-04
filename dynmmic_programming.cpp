#include <iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<math.h>
#include<climits>
#define ll unsigned long long
using namespace std;
int min_to_1(int n, int dp[]) { // coi change problm
	if (n == 1) {
		return 1;
	}
	int op1, op2, op3;
	op1 = op2 = op3 = INT_MAX;
	if (n % 3 == 0) {
		op1 = min_to_1(n / 3, dp) + 1;
	}
	if (n % 2 == 0) {
		op2 = min_to_1(n / 2, dp) + 1;
	}
	op3 = min_to_1(n - 1, dp) + 1;
	return min(min(op1, op2), op3);
}
int bootom_upto_1(int n) {//wrong_approach // coin change
	int dp[100] = {0};
	for (int i = 2; i <= n; i++) {
		int a, b, c;
		a = b = c = INT_MAX;
		if (i % 2 == 0)
			a = dp[i / 2];
		if (i % 3 == 0)
			b = dp[i] / 3;
		c = dp[i - 1];
		dp[i] = min(min(b, c), a) + 1;
	}
	return dp[n];

}
int min_coins(int a[], int t, int n, int dp[]) {
	if (t == 0)
		return 0;
	int ans = INT_MAX;
	if (dp[t] != 0) {
		return dp[t];
	}
	for (int i = 0; i < n; i++) {
		if (t - a[i] >= 0) {
			int sub = min_coins(a, t - a[i], n, dp);
			ans = min(ans, sub + 1);

		}
	}
	return dp[n] = ans;
}
int maximum_sum(int a[], int n) {
	int dp[n];
	int max_so_far = 0;
	dp[0] = a[0] > 0 ? a[0] : 0;
	for (int i = 1; i < n; i++) {
		dp[i] = dp[i - 1] + a[i];
		if (dp[i] < 0)
			dp[i] = 0;
		max_so_far = max(dp[i], max_so_far);
	}
	if (max_so_far == 0) {
		return *max_element(a, a + n);
	}
	else
		return max_so_far;

}

int profit(int wine[], int i, int j, int y, int dp[][100]) { // wine problem
	if (i > j)
		return 0;
	if (dp[i][j] != 0)
		return dp[i][j];
	int i1 = wine[i] * y + profit(wine, i + 1, j, y + 1, dp);
	int i2 = wine[j] * y + profit(wine, i, j - 1, y + 1, dp);
	return dp[i][j] = max(i1, i2);
}
int ladder_top_up(int n, int dp[], int k) {//n*K
	if (n == 0)//base case
		return 1;
	int ways = 0;
	if (dp[n] != 0)
		return dp[n];
	for (int i = 1; i <= k; i++) {
		if (n - i >= 0)
			ways += ladder_top_up(n - i, dp, k);
	}
	return dp[n] = ways;
}
int ladder_bottom_up(int n, int k) {// n*k
	int dp[100] = {0};
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] = 0;
		for (int j = 1; j <= k; j++) {
			if (i - j >= 0)
				dp[i] += dp[i - j];
		}
	}
	return dp[n];
}
int optimised_approach_ladder(int n, int k) {// n+k
	int dp[100] = {0};
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= k; i++)
		dp[i] = dp[i - 1] * 2;
	for (int i = k + 1; i <= n; i++)
		dp[i] = dp[i - 1] * 2 - dp[i - k - 1];
	return dp[n];
}
int rop_cut_problem(int a[], int n, int dp[]) {
	if (n <= 0)
		return 0;
	if (dp[n] != 0)
		return 0;
	int ans = INT_MIN;


	for (int i = 0; i < n; i++) {
		int sum ;
		int c = i + 1;
		sum = a[i] + rop_cut_problem(a, n - c, dp);


		ans = max(ans, sum);
	}
	return  dp[n] = ans;


}
int bottom_up_rop_cut(int a[], int n) {
	int dp[n + 1];
	dp[0] = 0;
	for (int length = 1; length <= n; length++) {
		int ans = INT_MIN;
		for (int i = 0; i < length; i++) {
			int cut = i + 1;
			int sum = a[i] + dp[length - cut];
			ans = max(ans, sum);
		}
		dp[length] = ans;
	}
	return dp[n];
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("ou.txt", "w", stdout);
#endif
	//int n; cin >> n;
	//int a[n];
	//for (int i = 0; i < n; i++) {
	//	cin >> a[i];
	//}
	int n, k; cin >> n >> k;
	int a[k];
	for (int i = 0; i < k; i++)
		cin >> a[i];
	sort(a, a + k);
	int f = n - 1;
	int ans = INT_MAX;
	for (int i = 0; i <= k - n; i++) {
		int sum = a[f] - a[i];
		ans = min(ans, sum);
		f++;
	}
	cout << ans;
}