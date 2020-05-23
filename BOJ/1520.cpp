#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int arr[505][505];
int dp[505][505];
int n, m;

int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };

bool outrange(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) return 1;
	return 0;
}

int dfs(int x, int y) {
	if (x == n - 1 && y == m - 1) return 1; //도착점에 도착함
	if (dp[x][y] != -1) return dp[x][y]; //이미 도착한 적이 있는 경우엔 값을 그냥 넘겨준다.

	dp[x][y] = 0;//방문체크 
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (outrange(nx,ny)) continue;
		if (arr[nx][ny] < arr[x][y]) {
			dp[x][y] += dfs(nx, ny);
		}
	}

	return dp[x][y]; //이걸 넘겨줘야한다
}


int main() {
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
			dp[i][j] = -1; //방문 체크를 0으로 해주기 때문에 초기화를 -1로 해주어야한다.
		}
	}

	printf("%d", dfs(0, 0));

}
