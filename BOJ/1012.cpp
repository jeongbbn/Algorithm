#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

vector<int>ans;
queue<pair<int, int>>q;

int check[51][51],cnt, arr[51][51], max_x, max_y;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool range(int dx, int dy) {
	if (dx < 0 || dy < 0 || dx > max_x -1 || dy > max_y -1)
		return false;
	return true;
}

void dfs(int x, int y) {
	check[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (range(nx, ny) && arr[nx][ny] == 1 && check[nx][ny] != 1) {
			dfs(nx, ny);
		}
	}
}

void bfs(int X,int Y) {
	check[X][Y] = 1;
	q.push(pair<int,int>(X,Y));
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (range(nx, ny) && arr[nx][ny] == 1 && check[nx][ny] != 1) {
				q.push(pair<int, int>(nx, ny));
				check[nx][ny] = 1;
			}
		}
	}
}

int main() {
	int t, k;
	scanf("%d", &t);
	for (int j = 0; j < t; j++) {
		scanf("%d %d %d", &max_x, &max_y, &k);
		for (int i = 0; i < k; i++) {
			int tempX, tempY;
			scanf("%d %d", &tempX, &tempY);
			arr[tempX][tempY] = 1;
		}

		for (int i = 0; i < max_x; i++) {
			for (int j = 0; j < max_y; j++) {
				if (arr[i][j] == 1 && check[i][j] != 1) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);

		for (int i = 0; i < max_x; i++) {
			memset(check[i], 0, sizeof(check[i]));
			memset(arr[i], 0, sizeof(arr[i]));
		}	
		cnt = 0;
	}
	return 0;
}
