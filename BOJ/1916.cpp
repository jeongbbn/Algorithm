#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<map>
#include <string>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int,pair<int, int>>pii;

vector<pi>adj[1005];
int dist[1005];
int main() {
	int n, m;
	scanf("%d%d", &n,&m);	
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);

		bool flag = 0;
		adj[a].push_back({ c,b });
	}
	int s, d;
	scanf("%d%d", &s, &d);
	for (int i = 1; i <= n; i++)
	{
		dist[i] = INF;
	}
	dist[s] = 0;
	
	priority_queue<pi, vector<pi>, greater<pi>>pq;
	pq.push({ 0,s });

	while (!pq.empty()) {
		int x = pq.top().second;
		int dists = pq.top().first;
		pq.pop();

		if (dist[x] != dists) continue;

		for (int i = 0; i < adj[x].size(); i++)
		{
			int nxt = adj[x][i].second;
			int cost = adj[x][i].first;

			if (dist[nxt] > cost + dists) {
				dist[nxt] = cost + dists;
				pq.push({ dist[nxt],nxt });
			}

		}
	}

	printf("%d", dist[d]);
}
