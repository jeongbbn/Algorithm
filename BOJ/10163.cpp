#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int arr[105][105];
int main() {
	int n;
	scanf("%d", &n);
	for (int t = 1; t <= n; t++)
	{
		int x, y, w, h;
		scanf("%d%d%d%d", &y, &x, &w, &h);

		for (int i = x; i < x + h; i++)
		{
			for (int j = y; j < y + w; j++)
			{
				arr[i][j] = t;
			}
		}
	}

	int ans[105] = { 0, };
	for (int i = 0; i < 105; i++)
	{
		for (int j = 0; j < 105; j++)
		{
			for (int m = 1; m <= n; m++)
			{
				if (m == arr[i][j]) ans[m]++;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", ans[i]);
	}
}
