#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<string>
#include <stack>
using namespace std;
#define INF 1e9+10

typedef pair<int, int>p;
int d[305][305];
p arr[305];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		arr[i] = { a,b };
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i == j) d[i][j] = 0;
			else d[i][j] = INF;


	for (int i = 1; i <= n; i++)
	{
		for (int j = i+1; j <= n; j++)
		{
			int a = arr[i].first;
			int b = arr[i].second;
			int l = arr[j].first;
			int r = arr[j].second;
			
			if (r < a || b < l) continue;
			d[i][j] = 1;
			d[j][i] = 1;
		}
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (d[a][b] == INF) d[a][b] = -1;
		printf("%d\n", d[a][b]);
	}

}
