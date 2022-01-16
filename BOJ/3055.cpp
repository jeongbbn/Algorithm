#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;

int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };

int r, c;
bool outrange(int x, int y) {
	if (x < 0 || y < 0 || x >= r || y >= c) return 1;
	return 0;
}
queue<pi>q, w;

char arr[55][55];
bool visit[55][55];
bool bfs(int size) {
	while (size--) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (arr[x][y] == 'D') return 1;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (outrange(nx, ny)) continue;
			if (arr[nx][ny] == '*') continue;
			if (arr[nx][ny] == 'X') continue;
			if (visit[nx][ny]) continue;

			visit[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
	return 0;
}

void water() {
	int wsize = w.size();
	while (wsize--) {
		int x = w.front().first;
		int y = w.front().second;
		w.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (outrange(nx, ny)) continue;
			if (arr[nx][ny] == '*') continue;
			if (arr[nx][ny] == 'X') continue;
			if (arr[nx][ny] == 'D') continue;

			arr[nx][ny] = '*';
			w.push({ nx,ny });
		}
	}

}



int main() {

	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			scanf(" %c", &arr[i][j]);
			if (arr[i][j] == 'S') { q.push({ i,j }); visit[i][j] = 1; arr[i][j] = '.'; }
			else if (arr[i][j] == '*') { w.push({ i,j }); }
		}
	}

	int day = 0;
	while (1) {
		int size = q.size();
		if (size == 0) break;
		water();
		if (bfs(size)) { printf("%d", day); return 0; }
		day++;
	}

	printf("KAKTUS");
}
