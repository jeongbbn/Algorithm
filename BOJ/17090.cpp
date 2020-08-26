#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int n, m;
int ans;
char arr[505][505];
int dp[505][505];

bool outrange(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) return 1;
	return 0;
}

int dfs(int x, int y) {

	if (dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 0;

	if (arr[x][y] == 'D') {
		if (outrange(x + 1, y)) return dp[x][y] = 1;
		else dp[x][y] = dfs(x + 1, y);
	}
	else if (arr[x][y] == 'U') {
		if (outrange(x - 1, y)) return dp[x][y] = 1;
		else dp[x][y] = dfs(x - 1, y);
	}
	else if (arr[x][y] == 'R') {
		if (outrange(x, y + 1)) return dp[x][y] = 1;
		else dp[x][y] = dfs(x, y + 1);
	}
	else {
		if (outrange(x, y - 1)) return dp[x][y] = 1;
		else dp[x][y] = dfs(x, y - 1);
	}
	return dp[x][y];
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf(" %c", &arr[i][j]);
			dp[i][j] = -1;
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (dp[i][j] == -1) dfs(i, j);
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ans += dp[i][j];

	printf("%d", ans);
}
