#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int dp[20][20];
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	k--;

	if (k == -1) k = 0;

	int dx = k / m;
	int dy = k % m;

	dp[0][0] = 1;

	for (int i = 0; i < n; i++)
		dp[i][0] = 1;

	for (int i = 0; i < m; i++)
		dp[0][i] = 1;

	for (int i = 1; i <= dx; i++)
	{
		for (int j = 1; j <= dy; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}



	for (int i = dx; i < n; i++)
		dp[i][dy] = dp[dx][dy];

	for (int i = dy; i < m; i++)
		dp[dx][i] = dp[dx][dy];

	for (int i = dx+1; i < n; i++)
	{
		for (int j = dy+1; j < m; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	printf("%d", dp[n - 1][m - 1]);
}
