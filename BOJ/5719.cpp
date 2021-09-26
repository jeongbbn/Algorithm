#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<map>
#include <string>
#include<math.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int main() {

	while (1) {
		int n, m;
		scanf("%d%d", &n, &m);
		if (n == 0 && m == 0) break;

		int s, d;
		scanf("%d%d", &s, &d);

		vector<pi>adj[505];
		vector<int>pre[505];
		int mindist[505];
		for (int i = 0; i < m; i++)
		{
			int u, v, p;
			scanf("%d%d%d", &u, &v, &p);
			adj[u].push_back({ p,v });
		}

		for (int i = 0; i < n; i++)
		{
			mindist[i] = INF;
		}
		mindist[s] = 0;

		priority_queue<pi, vector<pi>, greater<pi>>pq;
		pq.push({ 0, s });

		while (!pq.empty()) {
			auto now = pq.top(); pq.pop();
			int dist = now.first;
			int cur = now.second;

			if (mindist[cur] != dist) continue;

			for (int i = 0; i < adj[cur].size(); i++)
			{
				int cost = adj[cur][i].first;
				int nxt = adj[cur][i].second;

				if (mindist[nxt] >= cost + dist) {
					mindist[nxt] = cost + dist;
					pq.push({ mindist[nxt], nxt });

					pre[nxt].push_back(cur);
				}
			}
		}

		if (mindist[d] == INF) { printf("-1\n"); continue; }

		//bfs
		queue<int>q;
		q.push(d);
		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (int i = 0; i < pre[x].size(); i++)
			{
				int nx = pre[x][i];
				
				for (int j = 0; j < adj[nx].size(); j++)
				{
					if (adj[nx][j].second == x && adj[nx][j].first + mindist[nx] == mindist[x]) {
						adj[nx][j].first = -1;
						q.push(nx);
					}
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			mindist[i] = INF;
		}
		mindist[s] = 0;

		pq.push({ 0, s });

		while (!pq.empty()) {
			auto now = pq.top(); pq.pop();
			int dist = now.first;
			int cur = now.second;

			if (mindist[cur] != dist) continue;

			for (int i = 0; i < adj[cur].size(); i++)
			{
				int cost = adj[cur][i].first;
				int nxt = adj[cur][i].second;

				if (adj[cur][i].first == -1) continue;

				if (mindist[nxt] > cost + dist) {
					mindist[nxt] = cost + dist;
					pq.push({ mindist[nxt], nxt });
				}
			}
		}

		if (mindist[d] == INF) printf("-1\n");
		else printf("%d\n", mindist[d]);
	}
}
