#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int n;
char arr[1005][1005];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1};
bool visit[1005][1005];
queue<pii>q;
pi ans;

bool outrange(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n) return 1;
	return 0;
}

pi bfs() {
	int p = 0; //perimeter
	int a = 1; //area
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (outrange(nx, ny)) { p++; continue;}
			if (visit[nx][ny]) continue;
			if (arr[nx][ny] == '.') { p++; continue; }
			a++;
			visit[nx][ny] = 1;
			q.push({ {nx, ny}, dist + 1 });
		}
	}


	return { a,p };
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf(" %c", &arr[i][j]);
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == '#' && !visit[i][j]) {
				q.push({ { i,j }, 1 });
				visit[i][j] = 1;
				pi tmp = bfs();

				if (ans.first < tmp.first) ans = tmp;
				else if (ans.first == tmp.first && ans.second > tmp.second) ans = tmp;
			}
		}
	}

	printf("%d %d", ans.first, ans.second);
}
