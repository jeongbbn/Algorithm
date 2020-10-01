#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
using namespace std;
using ti3 = tuple<int, int, int>;
#define INF 1e9+10


int v, e;
int d[405][405];
int main() {
	scanf("%d%d", &v, &e);

	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++)
			d[i][j] = INF;

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (d[a][b] < c) continue;
		d[a][b] = c;
	}

	for (int k = 1; k <= v; k++)
	{
		for (int i = 1; i <= v; i++)
		{
			for (int j = 1; j <= v; j++)
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	int minn = INF;
	for (int i = 1; i <= v; i++)
		minn = min(d[i][i], minn);

	if (minn == INF) printf("-1");
	else printf("%d", minn);
}
