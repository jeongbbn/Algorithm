#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
using namespace std;
#define INF 1e9+10

int arr[305][305], dp[305][305];


int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]+arr[i][j];
		}
	}



	int k;
	scanf("%d", &k);
	for (int t = 0; t < k; t++)
	{
		int x, y, nx, ny;
		scanf("%d%d%d%d", &x,&y,&nx,&ny);
		int sum;
		sum = dp[nx][ny] - dp[x - 1][ny] - dp[nx][y - 1] + dp[x - 1][y - 1];
		printf("%d\n", sum);
	}

}
