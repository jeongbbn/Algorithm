#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
using namespace std;
#define INF 1e9+10

int arr[1005][1005], dp[1005][1005];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = max(dp[i - 1][j],max(dp[i][j - 1],dp[i - 1][j - 1])) + arr[i][j];
		}
	}

	printf("%d", dp[n][m]);

}
