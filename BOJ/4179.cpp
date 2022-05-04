#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<set>
#include<map>
#include <string>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n, m, k;
char arr[1005][1005];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
queue<pi>q;
queue<pi>jq;

bool outrange(int x, int y) {
	if (x<0 || y<0 || x>n - 1 || y>m - 1) return 1;
	return 0;
}

int visit[1005][1005];
int jvisit[1005][1005];
void fire() {
	int x = q.front().first;
	int y = q.front().second;
	visit[x][y] = 1;
	q.pop();

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (outrange(nx, ny)) continue;
		if (visit[nx][ny]) continue;

		if (arr[nx][ny] == '.' || arr[nx][ny] == 'J') {
			q.push({ nx,ny });
			visit[nx][ny] = 1;
			arr[nx][ny] = 'F';
		}
	}
}

bool jh() {
	int x = jq.front().first;
	int y = jq.front().second;
	jvisit[x][y] = 1;
	jq.pop();

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (outrange(nx, ny)) { return true; }
		if (jvisit[nx][ny]) continue;

		if (arr[nx][ny] == '.') {
			jq.push({ nx,ny });
			jvisit[nx][ny] = 1;
			arr[nx][ny] = 'J';
		}
	}
	return false;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf(" %c", &arr[i][j]);
			if (arr[i][j] == 'J') jq.push({ i,j });
			else if (arr[i][j] == 'F') q.push({ i,j });
		}

	int days = 0;
	while (1) {
		days++;
		int fsize = q.size();
		int jsize = jq.size();

		if (jsize == 0) {
			printf("IMPOSSIBLE"); return 0;
		}

		while (fsize--) {
			fire();
		}

		while (jsize--) {
			if (jh()) { printf("%d", days);  return 0; }
		}

	}
}
