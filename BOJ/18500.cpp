#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int>pi;

int r, c, n, trial[105];
bool arr[105][105], connect[105][105];
queue<pi>q;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool outrange(int x, int y) {
	if (x <= 0 || y <= 0 || x > r || y > c) return 1;
	return 0;
}

void bfs(int sx, int sy) {
	q.push({ sx,sy });
	connect[sx][sy] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (outrange(nx, ny)) continue;
			if (connect[nx][ny]) continue;
			if (!arr[nx][ny])  continue;

			q.push({ nx,ny });
			connect[nx][ny] = 1;
		}
	}
}

void init() {
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			connect[i][j] = 0;
}


void falling() {
	vector<pi>v;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (arr[i][j] && !connect[i][j]) {
				v.push_back({ i,j });
				arr[i][j] = 0;
			}
		}
	}

	if (v.size() == 0) return;

	bool isconnect = 0;
	while (1) {
		for (int i = 0; i < v.size(); i++)
		{
			int x = v[i].first;
			int y = v[i].second;
			if (x == 1 || connect[x - 1][y]) isconnect = 1;
		}
		if (isconnect) {
			for (int i = 0; i < v.size(); i++) arr[v[i].first][v[i].second] = 1;
			break;
		}
		else {
			for (int i = 0; i < v.size(); i++) v[i].first--;
		}
	}
}

void func(int dir, int st, int height) {
	init();

	for (int i = st; i <= c && i >= 1; i += dir)
	{
		if (arr[height][i]) {
			arr[height][i] = 0;
			break;
		}
	}

	for (int i = 1; i <= c; i++)
	{
		if (!arr[1][i]) continue;
		if (connect[1][i]) continue;

		bfs(1, i);
	}

	falling();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;
	for (int i = r; i >= 1; i--) {
		for (int j = 1; j <= c; j++) {
			char c; cin >> c;
			if (c == 'x') arr[i][j] = 1;
			else arr[i][j] = 0;
		}
	}

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> trial[i];

	for (int i = 1; i <= n; i++)
	{
		int dir = 1, st = 1;
		if (i % 2 == 0) { dir = -1; st = c; }
		func(dir, st, trial[i]);
	}

	for (int i = r; i >= 1; i--) {
		for (int j = 1; j <= c; j++) {
			if (arr[i][j]) cout << 'x';
			else cout << '.';
		}
		cout << "\n";
	}
}
