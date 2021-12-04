#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
using namespace std;
#define INF 1e9+10
typedef pair<int, int> pi;

struct pos {
	int x;
	int y;
	int dist;
};

char map[55][55];
int m, n, endX, endY, stX, stY;

int minn = INF;
bool ans[7];
int ans[7];
vector<pi>keys;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };

bool outrange(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) return 1;
	return 0;
}

pos findKey(int a, int b,int k) {
	queue<pos>q;
	bool visit[55][55] = { 0, };
	visit[a][b] = 1;
	q.push({ a,b, 0});

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dist = q.front().dist;
		q.pop();

		if (x == keys[ans[k]].first && y == keys[ans[k]].second) {
			return { x,y,dist};
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (outrange(nx, ny)) continue;
			if (map[nx][ny] == '#') continue;
			if (visit[nx][ny]) continue;
			visit[nx][ny] = 1;
			q.push({ nx,ny,dist + 1});
		}
	}
}

void P(int k) {
	if (keys.size()-1 == k) {
		int i = stX, j = stY, l = 0;
		int sum = 0;

		while (l<=k) {
			pos tmp = findKey(i, j, l);
			i = tmp.x; j = tmp.y;
			sum += tmp.dist; l++;
		}

		minn = min(sum, minn);
	}

	for (int i = 0; i < keys.size()-1; i++)
	{
		if (ans[i]) continue;
		ans[i] = 1;
		ans[k] = i;
		P(k + 1);
		ans[i] = 0;
	}

}

int main() {
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'S') {
				stX = i, stY = j;
			}
			else if (map[i][j] == 'E') {
				endX = i; endY = j;
			}
			else if (map[i][j] == 'X') {
				keys.push_back({ i,j });
			}
		}
	}
	ans[keys.size()] = keys.size();
	keys.push_back({ endX,endY });

	P(0);
	printf("%d", minn);
}
