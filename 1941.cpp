#include <iostream>
using namespace std;

char map[7][7];
int p;
bool visit[7][7];
int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };

bool outrange(int x, int y) {
	if (x < 0 || y < 0 || x>4 || y>4) return 1;
	else return 0;
}

void dfs(int x, int y, int dist, int cnt) {

	if (dist == 7) { 
		if (cnt >= 4) p++;
		return; 
	}

	if (map[x][y] == 'S') cnt++;
	visit[x][y] = 1;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (outrange(nx, ny)) continue;
		if (!visit[nx][ny]) dist++;
		dfs(nx, ny, dist, cnt);
	}
}

void init() {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			visit[i][j] = 0;

}

int main() {

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			scanf(" %c", &map[i][j]);


	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, 0, 0);
			init();
		}
	}

	printf("%d", p);
}
