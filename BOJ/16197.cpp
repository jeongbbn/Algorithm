#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

typedef struct nodes {
	int x1;
	int y1;
	int x2;
	int y2;
	int dist;
}node;

int n, m;
char arr[25][25];
bool visited[25][25][25][25];
vector<pi>coin;
queue<node>q;

int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };

bool outrange(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)return 1;
	return 0;
}

int bfs() {
	q.push({ coin[0].first,coin[0].second, coin[1].first, coin[1].second });
	visited[coin[0].first][coin[0].second][coin[1].first][coin[1].second] = 1;
	while (!q.empty()) {
		int x1 = q.front().x1;
		int x2 = q.front().x2;
		int y1 = q.front().y1;
		int y2 = q.front().y2;
		int dist = q.front().dist;
		q.pop();

		if (dist > 10) return -1;
		for (int i = 0; i < 4; i++)
		{
			int nx1 = x1 + dx[i];
			int nx2 = x2 + dx[i];
			int ny1 = y1 + dy[i];
			int ny2 = y2 + dy[i];

			//하나만 떨어트리는데, dist+1가 10이상일 수도 있다.
			if (outrange(nx1, ny1) && !outrange(nx2, ny2) && dist+1<=10) return dist + 1;
			else if (!outrange(nx1, ny1) && outrange(nx2, ny2) && dist + 1 <= 10) return dist + 1;
			else if (outrange(nx1, ny1) && outrange(nx2, ny2)) continue;
			else {
				if (visited[nx1][ny1][nx2][ny2]) continue;
				if (arr[nx1][ny1] == '#') {
					nx1 = x1; ny1 = y1;
				}
				if (arr[nx2][ny2] == '#') {
					nx2 = x2; ny2 = y2;
				}
				visited[nx1][ny1][nx2][ny2] = 1;
				q.push({ nx1, ny1, nx2, ny2, dist+1 });
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			scanf(" %c", &arr[i][j]);
			if (arr[i][j] == 'o') {
				coin.push_back({ i,j });
				arr[i][j] = '.';
			}
		}
	}
	cout << bfs();
}
