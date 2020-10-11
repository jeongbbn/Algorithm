#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef struct pair<int, int> pi;

int dx[] = { 0,-2,0,2 };
int dy[] = { 2,0,-2,0 };
int dz[] = { 0,-1,0,1 };
int dw[] = { 1,0,-1,0 };

bool visit[205][205];
vector<pi>trace;
int main() {
	int n;
	scanf("%d", &n);
	int x = 101, y = 101;
	visit[x][y] = 1;
	trace.push_back({ x, y });
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);

		visit[x + dx[a - 1]][y + dy[a - 1]] = 1;
		visit[x + dz[a - 1]][y + dw[a - 1]] = 1;
		trace.push_back({ x + dx[a - 1] , y + dy[a - 1] });
		x = x + dx[a - 1];
		y = y + dy[a - 1];
	}

	int visitcnt = 0;
	for (int l = 0; l < 205; l++) {
		for (int m = 0; m < 205; m++) {
			if (visit[l][m] == 1) visitcnt++;
		}
	}


	int t;
	scanf("%d", &t);

	int arr[105][55];
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	bool flag[105] = { 0, };
	int cnt = 0;
	for (int i = 0; i < t; i++)
	{
		for (int k = 0; k < trace.size(); k++)
		{
			int x = trace[k].first;
			int y = trace[k].second;

			bool tmp[205][205] = { 0, };
			tmp[x][y] = 1;
			int j;
			for (j = 0; j < n; j++)
			{
				int a = arr[i][j];

				if (visit[x + dx[a - 1]][y + dy[a - 1]] != 1) break;
				if (visit[x + dz[a - 1]][y + dw[a - 1]] != 1) break;
				tmp[x + dx[a - 1]][y + dy[a - 1]] = 1;
				tmp[x + dz[a - 1]][y + dw[a - 1]] = 1;

				x = x + dx[a - 1];
				y = y + dy[a - 1];
			}

			if (j == n) {
				int tmpcnt = 0;
				for (int l = 0; l < 205; l++)
					for (int m = 0; m < 205; m++)
						if (tmp[l][m] == 1) tmpcnt++;
				if (tmpcnt != visitcnt) continue;

				flag[i] = 1; cnt++;

				break;
			}
		}
	}

	printf("%d\n", cnt);
	for (int i = 0; i < t; i++)
	{
		if (!flag[i]) continue;
		for (int j = 0; j < n; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
