#include<bits/stdc++.h>
using namespace std;
#define INF 1e9+1
typedef pair<int, int> pi;
typedef pair<int, pair<int, int>> pii;

int n, m, emptyy;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int arr[55][55];
vector<pi>v;

bool outrange(int x, int y) {
	if (x<0 || y<0 || x>n - 1 || y>n - 1) return 1;
	return 0;
}

bool visit[15];
int key[15];
int ans = INF;

int bfs() {
	queue<pi>q;
	bool bfsvisit[55][55] = { 0, };
	int emp = emptyy;
	int maxx = -1;
	for (int i = 0; i < m; i++)
	{
		q.push({v[key[i]].first,v[key[i]].second});
		bfsvisit[v[key[i]].first][v[key[i]].second];
	}

	int day = 0;
	while (!q.empty()) {
		int size = q.size();

		if (emp == 0) {
			return day; 
		}
		while (size--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (outrange(nx, ny))continue;
				if (bfsvisit[nx][ny]) continue;
				if (arr[nx][ny] == 1) continue;
				if (arr[nx][ny] == 0) emp--;
				bfsvisit[nx][ny] = 1;
				q.push({nx,ny});
			}
		}
		day++;
	}	

	return INF;
}


void C(int k, int idx) {
	if (k == m) {
		int cnt = bfs();
		ans = min(cnt, ans);
		return;
	}

	for (int i = idx; i < v.size(); i++)
	{
		if (visit[i]) continue;
		visit[i] = 1;
		key[k] = i;
		C(k + 1, i + 1);
		visit[i] = 0;
	}

}

int main() {
	scanf("%d%d", &n, &m);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2)	v.push_back({ i,j });
			else if (arr[i][j] == 0) emptyy++;
		}
	}

	C(0, 0);
	if (ans == INF) ans = -1;
	printf("%d", ans);

}
