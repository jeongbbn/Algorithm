#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int sum[10000];
int tmp[10000];
int arr[705][705];
int dp[705][705];

int main() {
	int m, n;
	scanf("%d%d", &m, &n);

	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		for (int i = 0; i < a; i++)
			tmp[i] = 0;

		for (int i = a; i < a + b; i++)
			tmp[i] = 1;

		for (int i = a + b; i < a + b + c; i++)
			tmp[i] = 2;

		for (int i = 0; i < 2 * m - 1; i++)
			sum[i] += tmp[i];
	}

	for (int i = 0, j = m - 1; i < m-1; i++,j--)
	{
		dp[j][0] = sum[i] + 1;
	}
	for (int i = m-1, j = 0; i < m*2 - 1; i++, j++)
	{
		dp[0][j] = sum[i] + 1;
	}

	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < m; j++)
		{
			dp[i][j] = max(dp[i - 1][j - 1], max(dp[i][j - 1], dp[i - 1][j]));
		}
	}


	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	return 0;
}
