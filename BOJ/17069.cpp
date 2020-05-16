#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int arr[35][35];
long long dp[35][35][3];
//dp[x][y][flag] : 현재 상태가 flag
int n;

bool outrange(int x, int y) {
	if (x <= 0 || y <= 0 || x >= n+1 || y >= n+1) return 1;
	return 0;
}

long long dfs(int flag, int dx, int dy) {

	if (dx == n && dy == n) return 1;
	if (outrange(dx, dy)) return 0;
	if (dp[dx][dy][flag] != -1) return dp[dx][dy][flag];

	dp[dx][dy][flag] = 0;

	if (flag == 0) {

		if(arr[dx][dy+1] != 1) dp[dx][dy][flag] += dfs(0 ,dx, dy + 1);
		
		if (arr[dx+1][dy+1] != 1 && arr[dx][dy+1] != 1 && arr[dx+1][dy] != 1 )
			dp[dx][dy][flag] += dfs(2, dx + 1, dy + 1);
	}

	else if (flag == 1) {
		if (arr[dx+1][dy] != 1)
		dp[dx][dy][flag] += dfs(1, dx + 1, dy);

		if (arr[dx + 1][dy + 1] != 1 && arr[dx][dy + 1] != 1 && arr[dx + 1][dy] != 1)
		dp[dx][dy][flag] += dfs(2, dx + 1, dy + 1);
	}
	
	else {
		if (arr[dx][dy + 1] != 1)
		dp[dx][dy][flag] += dfs(0, dx, dy + 1);

		if (arr[dx + 1][dy] != 1)
		dp[dx][dy][flag] += dfs(1, dx + 1, dy);

		if (arr[dx + 1][dy + 1] != 1 && arr[dx][dy + 1] != 1 && arr[dx + 1][dy] != 1)
		dp[dx][dy][flag] += dfs(2, dx + 1, dy + 1);
	}

	return dp[dx][dy][flag];
}


int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
		}

	for (int k = 0; k < 3; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j][k] = -1;
			}
		}
	}

	dfs(0, 1, 2);

	long long ans = 0;
	for (int i = 0; i < 3; i++)
	{
		if (dp[1][2][i] == -1) continue;
		ans += dp[1][2][i];
	}
	printf("%lld", ans);
}
