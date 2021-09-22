#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<map>
#include <string>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int d[405][405];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);

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
		int a, b;
		scanf("%d%d", &a, &b);
		d[a][b] = 1;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (d[i][j] > (d[i][k] + d[k][j])) {
					d[i][j] = 1;
				}
			}
		}
	}

	int s;
	scanf("%d", &s);
	for (int i = 0; i < s; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);

		if (d[a][b] == INF && d[b][a] == INF)  printf("0\n");
		else if(d[a][b] != 1 && d[b][a] == 1) printf("1\n");
		else if (d[a][b] == 1 && d[b][a] != 1) printf("-1\n");

	}

}
