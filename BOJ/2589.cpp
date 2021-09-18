#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
using namespace std;
using ti3 = tuple<int, int, int>;
#define INF 1e9+10

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m;
char arr[55][55];
bool outrange(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) return 1;
	return 0;
}

int distMax = -1;
void bfs(int k, int kk) {
	bool visit[55][55] = { 0, };
	queue<ti3>q;
	visit[k][kk] = 1;
	q.push({ k,kk,0 });
	while (!q.empty()) {
		int x, y, dist;
		tie(x, y, dist) = q.front();
		distMax = dist > distMax ? dist : distMax;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (outrange(nx, ny)) continue;
			if (arr[nx][ny] == 'W') continue;
			if (visit[nx][ny]) continue;
			q.push({ nx,ny,dist + 1 });
			visit[nx][ny] = 1;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf(" %c", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(arr[i][j]=='L')
				bfs(i, j);
		}
	}
	printf("%d", distMax);
}
