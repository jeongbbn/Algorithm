#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n, k;
int dp[15][4];

int main() {
	scanf("%d%d", &n, &k);
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 2;
	dp[3][2] = 1;
	dp[3][3] = 1;

	for (int i = 4; i <= n; i++) {
		dp[i][1] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3];
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2] + dp[i - 2][3];
		dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
	}

	if (k > dp[n][1] + dp[n][2] + dp[n][3]) {
		printf("-1");
		return 0;
	}
	int x = n;
	while (x >= 0) {
		for (int i = 1; i < 4; i++)
		{
			if (k <= dp[x][i]) {
				x -= i;
				printf("%d", i);
				break;
			}
			else {
				k -= dp[x][i];
			}
		}
		if (x == 0) break;
		printf("+");
	}
}
