#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int>pi;

typedef struct nodes {
	pi red;
	pi blue;
	int dist;
}node;

int n, m, ans;
char arr[15][15];
pi st_red, st_blue, hole;
bool visited[15][15][15][15];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

pi findPOS(pi color, int i, pi another) {
	int color_x = color.first;
	int color_y = color.second;

	while (arr[color_x + dx[i]][color_y + dy[i]] == '.') {
		if (hole.first == color_x + dx[i] && hole.second == color_y + dy[i]) 
			return { color_x + dx[i], color_y + dy[i] };
		if (another.first == color_x + dx[i] && another.second == color_y + dy[i]) break;
		color_x += dx[i];
		color_y += dy[i];
	}

	return { color_x, color_y };
}

bool isRedFirst(pi red, pi blue, int i) {
	int sum_red = (red.first * dx[i]) + (red.second * dy[i]);
	int sum_blue = (blue.first * dx[i]) + (blue.second * dy[i]);

	if (sum_red > sum_blue) return 1;
	else return 0;
}


bool bfs() {
	queue<node>q;
	q.push({ st_red, st_blue, 0 });
	visited[st_red.first][st_red.second][st_blue.first][st_blue.second] = 1;

	while (!q.empty()) {
		pi red = q.front().red;
		pi blue = q.front().blue;
		int dist = q.front().dist;
		q.pop();

		if (dist > 10) continue;
		if (blue == hole) continue;

		if (red == hole) {
			ans = dist;
			return 1;
		}

		for (int i = 0; i < 4; i++)
		{
			pi new_red, new_blue;
			if (isRedFirst(red, blue, i)) {
				new_red = findPOS(red, i, {0,0});
				new_blue = findPOS(blue, i, new_red);
			}
			else {
				new_blue = findPOS(blue, i, { 0,0 });
				new_red = findPOS(red, i, new_blue);
			}
			
			if (visited[new_red.first][new_red.second][new_blue.first][new_blue.second]) 
				continue;

			visited[new_red.first][new_red.second][new_blue.first][new_blue.second] = 1;
			q.push({ new_red , new_blue, dist + 1 });
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c; cin >> c;
			arr[i][j] = c;

			if (c == '#') continue;

			if (c == 'R') st_red = { i,j };
			else if(c=='B') st_blue = { i,j };
			else if (c == 'O') hole = { i,j };
			arr[i][j] = '.';
		}
	}

	if (bfs()) cout << ans;
	else cout << -1;
}
