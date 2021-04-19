#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pi;
typedef pair<pi, bool> pii;

int n, m, arr[1005][1005], ans;
int dist[1005][1005][2];
int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };
queue<pii>q;

bool outrange(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) return 1;
	return 0;
}

void bfs() {
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		bool flag = q.front().second;
		q.pop();
	
		if (x == n - 1 && y == m - 1) {
			ans = dist[x][y][flag];
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (outrange(nx, ny)) continue;
			if (dist[nx][ny][flag] != 0) continue;
			if (!flag && arr[nx][ny] == 1) {
				dist[nx][ny][1] = dist[x][y][0] + 1;
				q.push({ {nx,ny}, 1});
			}

			if (arr[nx][ny] == 0) {
				dist[nx][ny][flag] = dist[x][y][flag] + 1;
				q.push({ {nx,ny}, flag });
			}
		}
	}
}

int main() {
	scanf("%d%d",&n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &arr[i][j]);

	q.push({ {0,0},0 });
	dist[0][0][0] = 1;
	bfs();

	if (ans == 0) cout << -1;
	else cout << ans;
}
