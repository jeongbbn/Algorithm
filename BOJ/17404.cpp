#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n, first;
int dp[1005][3];
int arr[1005][3];

int dfs(int k, int c) {
	if (dp[k][c] != 0) return dp[k][c];
	if (k == n-1) {
		if (first == c) return INF;
		return arr[k][c];
	}

	if (c == 0) {
		int tmp1 = arr[k][c] + dfs(k + 1, 1);
		int tmp2 = arr[k][c] + dfs(k + 1, 2);
		dp[k][c] = min(tmp1, tmp2);
	}
	else if (c == 1) {
		int tmp1 = arr[k][c] + dfs(k + 1, 0);
		int tmp2 = arr[k][c] + dfs(k + 1, 2);
		dp[k][c] = min(tmp1, tmp2);
	}
	else {
		int tmp1 = arr[k][c] + dfs(k + 1, 0);
		int tmp2 = arr[k][c] + dfs(k + 1, 1);
		dp[k][c] = min(tmp1, tmp2);
	}
	
	return dp[k][c];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
	}

	int ans = INF;
	for (int i = 0; i < 3; i++)
	{
		first = i;
		for (int j = 0; j < n; j++)
		{
			dp[j][0] = 0;
			dp[j][1] = 0;
			dp[j][2] = 0;
		}
		ans = min(ans,dfs(0,i));
	}
	printf("%d", ans);
}
