#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 100003
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };

int r, c, ans;
char arr[25][25];

bool outrange(int x, int y) {
	if (x < 0 || y < 0 || x >= r || y >= c) return 1;
	return 0;
}

void dfs(int x, int y, int visit, int dist) {
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (outrange(nx, ny)) continue;
		int now = arr[nx][ny] - 65;
		if (visit&(1 << now)) continue;
		dfs( nx, ny, visit | (1 << now), dist + 1 );
	}
	ans = max(ans, dist);
}

int main() {
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			scanf(" %c", &arr[i][j]);

	int status = 0;
	status |= (1 << (arr[0][0] - 65));
	dfs(0, 0, status, 1);
	printf("%d", ans);
}
