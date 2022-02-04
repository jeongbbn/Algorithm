#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int dx[6] = { 0, 0, 0, 0, 1, -1 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 1, -1, 0, 0, 0, 0 };
int n, m, h;

bool range(int x, int y, int z) {
	if (x < 0 || y < 0 || x > n - 1 || y > m - 1 || z < 0 || z > h-1 ) return 0;
	return 1;
}

int arr[101][101][101];
queue<pair<int,pair<int, int>>>q;

void bfs(int z, int x, int y) {
	for (int i = 0; i < 6; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		int nz = z + dz[i];

		if (range(nx, ny, nz) && arr[nz][nx][ny] == 0) {
			q.push(make_pair(nz, make_pair(nx, ny)));
			arr[nz][nx][ny] = 1;
		}
	}
}

int main() {
	int day = -1;
	scanf("%d %d %d", &m, &n, &h);
	
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &arr[k][i][j]);
				if (arr[k][i][j] == 1) q.push(make_pair(k, make_pair(i, j)));
			}
		}
	}

	while (!q.empty()) {
		int size = q.size();
		while (size != 0) {
			bfs(q.front().first,q.front().second.first, q.front().second.second);
			q.pop();
			size--;
		}
		day++;
	}
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[k][i][j] == 0) {
					printf("-1");
					return 0;
				}
			}
		}
	}
	printf("%d", day);
	return 0;
}
