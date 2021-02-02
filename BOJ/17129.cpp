#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

char arr[3005][3005];
int visit[3005][3005];
queue <pi>q;

int n, m;
int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };

bool outrange(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) return 1;
	return 0;
}
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (arr[x][y] == '3' || arr[x][y] == '4' || arr[x][y] == '5') {
			printf("TAK\n");
			printf("%d", visit[x][y] - 1);
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (outrange(nx, ny)) continue;
			if (arr[nx][ny] == '1') continue;
			if (visit[nx][ny] > 0) continue;

			visit[nx][ny] = visit[x][y] + 1;
			q.push({ nx,ny });
		}
	}
	printf("NIE");
}

int main() {
	scanf("%d%d", &n,&m);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", arr[i]);

		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == '2') {
				visit[i][j] = 1;
				q.push({ i,j });
			}
		}
	}

	bfs();
}
