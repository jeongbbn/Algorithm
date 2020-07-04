#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n;
pi arr[1500005];
int dp[1500005];

int dfs(int s) {
	if (dp[s] > 0) return dp[s];
	if (s > n) return 0;

	int tmp1 = 0, tmp2 = 0;
	if(arr[s].first + s <= n + 1)
		tmp1 = arr[s].second + dfs(arr[s].first + s);

	if(s + 1 <= n + 1)
		tmp2 = dfs(s + 1);

	dp[s] = dp[s] + max(tmp1, tmp2);

	return dp[s];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &arr[i].first, &arr[i].second);

	for (int i = 1; i <= n; i++)
	{
		dfs(i);
	}

	printf("%d", *max_element(dp, dp + n + 1));
}
