#include <iostream>
#include <algorithm>
using namespace std;

int dp[2][100'005];
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);

		dp[0][0] = 0;
		dp[1][0] = 0;

		for (int k = 0; k < 2; k++)
		{
			for (int j = 1; j <= n; j++) {
				scanf("%d", &dp[k][j]);
			}
		}

		for (int j = 2; j <= n; j++) {
			dp[0][j] += max(dp[1][j - 2], dp[1][j - 1]);
			dp[1][j] += max(dp[0][j - 2], dp[0][j - 1]);
		}
		int ans = max(dp[0][n], dp[1][n]);
		printf("%d\n", ans);

	}
}

