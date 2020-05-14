#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

typedef struct {
	int x;
	int y;
	int wall; 
}node;
int arr[105][105];
int visit[105][105][2];
queue<node>q;
int n, m, t;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool outrange(int x, int y) {
	if (x <= 0 || y <= 0 || x > n || y > m) return 1;
	return 0;
}

void bfs() {
	visit[1][1][0] = 1;
	q.push({ 1,1,0 });

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int wall = q.front().wall;
		q.pop();

		if (visit[x][y][wall]-1 > t) continue;
		if (x == n && y == m) { 
			printf("%d", visit[x][y][wall]-1);
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (outrange(nx, ny)) continue;
			if (visit[nx][ny][wall] > 0) continue; 

			if (arr[nx][ny] == 2) {
				visit[nx][ny][wall] = visit[x][y][wall] + 1;
				visit[nx][ny][1] = visit[x][y][wall] + 1;
				q.push({ nx,ny,1 });
			}


			if (wall == 1) { 
				visit[nx][ny][wall] = visit[x][y][wall] + 1;
				q.push({ nx,ny,wall});
			}

			else { 
				if (arr[nx][ny] == 1) continue;
				visit[nx][ny][wall] = visit[x][y][wall] + 1;
				q.push({ nx,ny,wall});
			}

		}
	}
	printf("Fail");
	return;
}

int main() {
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	bfs();
}
