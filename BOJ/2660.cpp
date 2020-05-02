#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int d[55][55];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			d[i][j] = INF;
			if (i == j) d[i][j] = 0;
		}
	}

	while (1) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a == -1 && b == -1)	break;

		d[a][b] = 1;
		d[b][a] = 1;
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

	int ans[55] = { 0, };
	int minn = INF;
	for (int j = 1; j <= n; j++)
	{
		int maxTmp = 0;
		for (int k = 1; k <= n; k++)
		{
			maxTmp = max(maxTmp, d[j][k]);
		}
		ans[j] = maxTmp;
		minn = min(minn, maxTmp);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (ans[i] == minn) cnt++;
	}

	printf("%d %d\n", minn, cnt);
	for (int i = 1; i <= n; i++)
	{
		if (ans[i] == minn) printf("%d ", i);
	}
}
