#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n, m, sum, ans;
int arr[5][5], s, t;
bool visit[5][5];

bool outrange(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) return 1;
	return 0;
}

//선택되지 않은 공간을 찾아준다.
bool check() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!visit[i][j]) {
				s = i; t = j; return 1;
			}
	return 0;
}

void dfs(int x, int y) {
	//세로
	for (int i = 0; i < n; i++)
	{
		//visit[x+i][y] >> 이미 방문한 공간도 가면 안된다.
		if (outrange(x + i, y) || visit[x + i][y]) break;
		for (int a = 0; a <= i; a++)
		{
			visit[x + a][y] = 1;
			sum += (arr[x + a][y] * pow(10, i - a));
		}

		if (!check()) ans = max(ans, sum);
		else dfs(s, t);

		for (int a = 0; a <= i; a++)
		{
			visit[x + a][y] = 0;
			sum -= (arr[x + a][y] * pow(10, i - a));
		}
	}

	//가로
	//j=1부터 시작해서 하나를 선택하는 것에대한 중복을 줄임
	for (int j = 1; j < m; j++)
	{
		if (outrange(x, y + j) || visit[x][y + j]) break;
		for (int a = 0; a <= j; a++)
		{
			visit[x][y + a] = 1;
			sum += (arr[x][y + a] * pow(10, j - a));
		}

		if (!check()) ans = max(ans, sum);
		else dfs(s, t);

		for (int a = 0; a <= j; a++)
		{
			visit[x][y + a] = 0;
			sum -= (arr[x][y + a] * pow(10, j - a));
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}

	dfs(0, 0);
	printf("%d", ans);
}
