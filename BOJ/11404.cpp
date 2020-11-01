#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
#define INF 1e9+10
int n, m;
int arr[105][105];
int main() {
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) arr[i][j] = 0;
			else arr[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b,&c);
		if (arr[a][b] != 0) {
			arr[a][b] = min(c, arr[a][b]);
		}
		else arr[a][b] = c;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == INF) arr[i][j] = 0;
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}

}
