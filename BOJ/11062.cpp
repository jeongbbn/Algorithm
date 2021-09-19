#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int t, arr[1005];
int dp[2][1005][1005];


int dfs(int st, int l, int r) {
	if (l > r) return 0;
	if (dp[st][l][r] != -1) return dp[st][l][r];

	dp[st][l][r] = 0;
	if (st == 0) {
		dp[st][l][r] = max(dfs(1, l + 1, r) + arr[l], dfs(1, l, r - 1) + arr[r]);
	}
	else {
		dp[st][l][r] = min(dfs(0, l + 1, r), dfs(0, l, r - 1));
	}
	return dp[st][l][r];
}

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(arr, 0, sizeof(arr));
		memset(dp, -1, sizeof(dp));

		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}

		printf("%d\n",dfs(0, 0, n - 1));
	}
}
