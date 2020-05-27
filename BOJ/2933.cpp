#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int r, c;
char arr[105][105];
bool visit[105][105];
vector<pi>v;
queue<pi>q;

int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };

bool outrange(int x, int y) {
	if (x < 0 || y < 0 || x >= r || y >= c) return 1;
	return 0;
}

void bfs(int sx, int sy) {
	visit[sx][sy] = 1;
	q.push({ sx,sy });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (outrange(nx, ny)) continue;
			if (visit[nx][ny]) continue;
			if (arr[nx][ny] == '.') continue;
			q.push({ nx,ny });
			visit[nx][ny] = 1;
		}
	}
}

void init() {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			visit[i][j] = 0;

	v.clear();
}

void falling() {
	bool flag = 0;
	while (1) {
		for (int i = 0; i < v.size(); i++)
		{
			int x = v[i].first;
			int y = v[i].second;

			if (x + 1 == r || (arr[x + 1][y] == 'x' && visit[x + 1][y])) flag = 1;
		}
		//한 칸씩 내려가며 확인
		if (!flag) for (int i = 0; i < v.size(); i++) v[i].first += 1;
		else {
			for (int i = 0; i < v.size(); i++) {
				int x = v[i].first;
				int y = v[i].second;
				arr[x][y] = 'x';
			}
			break;
		}
	}

}

void deonjim(int dir, int st, int h) {

	init();

	//막대기 던져서 미네랄을 깸
	for (int i = st; i >= 0 && i < c; i += dir)
	{
		if (arr[h][i] == '.') continue;
		arr[h][i] = '.';
		break;
	}

	//클러스터 확인
	//바닥과 붙어있는 경우엔 visit이 체크되어있다.
	for (int j = 0; j < c; j++)
	{
		if (arr[r - 1][j] == 'x' && !visit[r - 1][j]) bfs(r - 1, j);
	}

	//visit 체크 안되어있는 것들 중 == 공중에 떠있는 것들 체크
	for (int i = r - 1; i >= 0; i--) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'x' && !visit[i][j]) {
				v.push_back({ i,j });
				arr[i][j] = '.';
			}
		}
	}

	//공중에 떠 있는게 있다면 
	if (v.size() != 0) falling();
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
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a, dir = 1, st = 0;
		scanf("%d", &a);

		if (i % 2 == 1) { dir = -1; st = c - 1; }
		deonjim(dir, st, r - a);
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}
