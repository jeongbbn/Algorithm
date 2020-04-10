#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;

int mindist[1005][1005]; //[x][y] x노드에서 y노드까지의 거리
int n, m;
vector<pi>adj[1005];
queue<pi>q;

void bfs(int a) {
	bool visit[1005] = { 0, };
	visit[a] = 1;
	q.push({ a,0 });
	while (!q.empty()) {
		int x = q.front().first;
		int dist = q.front().second;
		q.pop();

		for (int i = 0; i < adj[x].size(); i++)
		{
			int nxt = adj[x][i].first;
			int cost = adj[x][i].second;

			if (visit[nxt]) continue;
			mindist[a][nxt] = dist + cost;
			mindist[nxt][a] = dist + cost;
			visit[nxt] = 1;
			q.push({ nxt,dist + cost});
		}

	}
}

int main() {
	scanf("%d%d", &n,&m);
	for (int i = 0; i < n-1; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	for (int i = 1; i <= n; i++)
	{
		bfs(i);
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", mindist[a][b]);

	}
}
