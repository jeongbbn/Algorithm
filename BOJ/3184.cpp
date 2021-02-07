#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int r, c;
pi ans;
char arr[255][255];
bool visited[255][255];
queue<pi>q;
int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };

void bfs(int sx, int sy) {
	int o = 0, v = 0;

	if (arr[sx][sy] == 'o') o++;
	else if (arr[sx][sy] == 'v') v++;
	visited[sx][sy] = 1;
	q.push({ sx,sy });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (visited[nx][ny]) continue;
			if (arr[nx][ny] == '#') continue;
			if (arr[nx][ny] == 'o') o++;
			if (arr[nx][ny] == 'v') v++;

			visited[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}

	if (o > v) ans.first += o;
	else ans.second += v;
}

int main() {
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			scanf(" %c", &arr[i][j]);
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] == '#') continue;
			if (!visited[i][j]) bfs(i, j);
		}
	}
	printf("%d %d", ans.first, ans.second);
	return 0;
}
