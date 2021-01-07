/*
Codeforces Round #693 (Div. 3)
C. Long Jumps
*/

#include<iostream>
#include<algorithm>
using namespace std;
 
int tc, n, arr[200005], dp[200005];
 
int dfs(int x, int cnt) {
	if (x > n) return cnt;
	if (dp[x] != -1) return dp[x];
	dp[x] = 0;
	dp[x] = dfs(x + arr[x], cnt + arr[x]);
	return dp[x];
}
 
int main() {
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			dp[i] = -1;
		}
		for (int i = 1; i <= n; i++) dfs(i, 0);
		cout << *max_element(dp + 1, dp + n + 1) << "\n";
	}
}
