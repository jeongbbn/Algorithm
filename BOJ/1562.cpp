#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000000
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

int n, ans;
int dp[105][10][1 << 10];

int dfs(int x, int cnt, int visited) {
	if (dp[cnt][x][visited] != -1) return dp[cnt][x][visited];
	if (cnt == n) {
		if (visited == (1 << 10) - 1) return 1;
		return 0;
	}

	int res1 = 0, res2 = 0;
	if(x < 9) res1 = dfs(x + 1, cnt + 1, visited | (1 << (x + 1)));
	if(x > 0) res2 = dfs(x - 1, cnt + 1, visited | (1 << (x - 1)));

	dp[cnt][x][visited] = (res1 + res2) % mod;
	return dp[cnt][x][visited];
}


void init() {
	for (int i = 0; i <= n; i++)
	{
		for (int h = 0; h < 10; h++)
		{
			for (int j = 0; j < (1<<10); j++)
			{
				dp[i][h][j] = -1;
			}
		}
	}
}
int main() {
	scanf("%d", &n);

	init();

	for (int i = 1; i <= 9; i++)
	{
		ans = (ans + dfs(i, 1, 1 << i)) % mod;
	}
	printf("%d", ans);
}
