#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
int n, m, arr[55][55];
int main() {
	scanf("%d%d", &n,&m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char a;
			scanf(" %c", &a);
			if (a == 'W') arr[i][j] = 1;
			else arr[i][j] = 0;
		}
	}
	int ans = INF;
	for (int i = 0; i+8 <= n; i++)
	{
		for (int j = 0; j + 8 <= m; j++)
		{
			for (int c = 0; c < 2; c++)
			{
				int cnt = 0;
				int flag = (i + j) % 2;

				for (int k = i; k < i+8; k++)
				{
					for (int l = j; l < j+8; l++)
					{
						if ((k + l) % 2 == flag) {
							if (arr[k][l] != c) cnt++;
						}
						else {
							if (arr[k][l] == c) cnt++;
						}
					}
				}

				ans = min(ans, cnt);
			}
		}
	}
	printf("%d", ans);
}
