#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define digit 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int t, n;
int dp[65][65][65];
int dx[6][3] = { {9,1,3}, {9,3,1},{3,1,9}, {3,9,1}, {1,3,9},{1,9,3} };

int dfs(int a, int b, int c) {
	if (dp[a][b][c] != 0) return dp[a][b][c];
	if (a == 0 && b == 0 && c == 0) return 1;

	dp[a][b][c] = INF;
	for (int i = 0; i < 6; i++)
	{
		int na = max(0, a - dx[i][0]);
		int nb = max(0, b - dx[i][1]);
		int nc = max(0, c - dx[i][2]);
		dp[a][b][c] = min(dp[a][b][c], 1 + dfs(na, nb, nc));
	}

	return dp[a][b][c];
}

int main() {
	scanf("%d", &n);
	int arr[3] = { 0, };
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	printf("%d", dfs(arr[0], arr[1], arr[2]) - 1);
}
