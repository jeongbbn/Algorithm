
/* 출력 초과가 나왔던 문제, overflow 때문이었다.*/

#include <bits/stdc++.h>
using namespace std;
#define INF 1e14
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
typedef pair<int, int>p;

int n, m;
long long dist[505];
vector<p>adj[505];
int main() {
	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back({ b,c });
	}

	fill(dist, dist + n + 1, INF);
	dist[1] = 0;

	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		for (int x = 1; x <= n; x++)
		{
			for (int j = 0; j < adj[x].size(); j++)
			{
				int nxt = adj[x][j].first;
				int cost = adj[x][j].second;

				if (dist[x] != INF && dist[x] + cost < dist[nxt]) {
					dist[nxt] = dist[x] + cost;
					if (i == n - 1) flag = true;
				}
			}
		}
	}

	if (flag) printf("-1\n");
	else {
		for (int i = 2; i <= n; i++)
		{
			if (dist[i] == INF) printf("-1\n");
			else printf("%lld\n", dist[i]);
		}
	}
}
