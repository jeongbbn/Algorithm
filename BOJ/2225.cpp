#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int dp[205][205];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	
	for (int i = 0; i <= n; i++)
		dp[i][1] = 1;

	for (int i = 1; i <= k; i++)
		dp[0][i] = 1;

	for (int j = 1; j <= k; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int m = 0; m <= i; m++)
			{
				dp[i][j] = (dp[i][j] + dp[m][j - 1]) % 1000000000;
			}                                                                                              
		}
	}
	
	printf("%d", dp[n][k]);
}
