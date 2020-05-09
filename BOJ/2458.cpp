#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

vector<int>bigger[505], smaller[505];
int n, m;
int bindegree[505], sindegree[505];
queue<int>q;

int lose[505], win[505];

int bfs(int s, vector<int> arr[]) {

	bool visit[505] = { 0, };
	int cnt = 0;
	q.push(s);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < arr[x].size(); i++)
		{
			int y = arr[x][i];

			if (visit[y]) continue;
			visit[y] = 1;
			q.push(y);
			cnt++;
		}

	}
	return cnt;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		smaller[b].push_back(a);
		bigger[a].push_back(b);
	}

	for (int i = 1; i <= n; i++)
	{
		lose[i] = n - bfs(i, smaller);
		win[i] = bfs(i, bigger) + 1;

	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (lose[i] == win[i]) ans++;
	}
	printf("%d", ans);
}
