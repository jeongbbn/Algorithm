#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define digit 1000000009
typedef pair<int, int>pi;

int t;
long long dp[1005][1005];
long long ans[1005][1005];

int main() {
	scanf("%d", &t);

	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 2;
	dp[3][3] = 1;

	//dp[1][1] = 1;
	//dp[2][1] = 1;
	//dp[2][2] = 2;
	//dp[3][1] = 1;
	//dp[3][2] = 3;
	//dp[3][3] = 4;

	for (int i = 4; i <= 1000; i++) {
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 2][j - 1]) % digit + dp[i - 3][j - 1]) % digit;
		}
	}

	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= i; j++)
		{
			ans[i][j] = (dp[i][j] + ans[i][j - 1]) % digit;
		}
	}

	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		printf("%lld\n", ans[n][k]);
	}
}
