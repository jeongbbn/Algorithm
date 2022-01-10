#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int>pi;
typedef pair<pi, int>pii;

typedef struct nodes {
	int num;
	int dir;
}node;

int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,-1,-1,-1,0,1,1,1 };
int ans;
node arr[5][5];

bool outrange(int x, int y) {
	if (x <= 0 || y <= 0 || x > 4 || y > 4) return 1;
	return 0;
}

void func(node MAP[][5], int sx, int sy, node shark) {

	//shark eats
	shark.num += MAP[sx][sy].num;
	shark.dir = MAP[sx][sy].dir;

	MAP[sx][sy].num = 0;
	MAP[sx][sy].dir = 0;

	//fish moves
	pii number[20] = { {{0,0},0,}, };

	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			if (MAP[i][j].num == 0) continue;
			number[MAP[i][j].num] = { {i,j}, MAP[i][j].dir };
		}
	}

	for (int fish = 1; fish <= 16; fish++)
	{
		int x = number[fish].first.first;
		int y = number[fish].first.second;
		int dir = number[fish].second;

		if (x == 0) continue;

		for (int i = 0; i < 8; i++, dir++)
		{
			if (dir == 8) dir = 0;
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (outrange(nx, ny)) continue;
			if (sx == nx && sy == ny) continue;

			//swap
			MAP[x][y].dir = dir;
			number[fish].second = dir;
			swap(MAP[x][y], MAP[nx][ny]);
			swap(number[fish].first, number[MAP[x][y].num].first);
			break;
		}
	}

	//next
	for (int t = 1; t <= 3; t++)
	{
		int nsx = sx + (dx[shark.dir] * t);
		int nsy = sy + (dy[shark.dir] * t);

		if (outrange(nsx, nsy)) continue;
		if (MAP[nsx][nsy].num == 0) continue;

		node temp_MAP[5][5] = { {0,0}, };
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
				temp_MAP[i][j] = MAP[i][j];

		func(temp_MAP, nsx, nsy, shark);
	}

	ans = max(ans, shark.num);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			int a, b;
			cin >> a >> b;
			arr[i][j] = { a,b - 1};
		}
	}

	func(arr, 1, 1, { 0,0 });
	cout << ans;
}
