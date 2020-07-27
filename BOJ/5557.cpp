#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n, arr[105];
long long dp[105][25];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	dp[0][arr[0]] = 1;

	for (int i = 1; i < n-1; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if (dp[i - 1][j] != 0) {
				if (j + arr[i] <= 20)
					dp[i][j + arr[i]] += dp[i - 1][j];

				if (j - arr[i] >= 0)
					dp[i][j - arr[i]] += dp[i - 1][j];
			}
		}
	}

	printf("%lld", dp[n - 2][arr[n-1]]);
}
