#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
using namespace std;
#define INF 1e9+10

int sum[1005];
int d[1005][1005];

int main() {
	int n, m, x;
	scanf("%d %d %d", &n, &m, &x);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) d[i][j] = 0;
			else d[i][j] = INF;
		}
	}


	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (d[a][b] < c) continue;
		d[a][b] = c;
	}



	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		sum[i] += d[i][x];
		sum[i] += d[x][i];
	}

	printf("%d", *max_element(sum, sum + n + 1));

}
