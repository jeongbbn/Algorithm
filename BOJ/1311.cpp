#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define WEIGHT 500
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<int, pi>pii;

int n, arr[25][25];
int dp[20][1 << 21];

int dfs(int x, int visited) {
	if (visited == (1 << n) - 1) return 0;
	if (dp[x][visited] != -1) return dp[x][visited];

	dp[x][visited] = INF;
	for (int i = 0; i < n; i++)
	{
		if (visited & (1 << i)) continue;
		dp[x][visited] = min(dp[x][visited], 
			dfs(x + 1, visited | (1 << i)) + arr[x][i]);
	}
	return dp[x][visited];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0);
}
