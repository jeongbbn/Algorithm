#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
using namespace std;
#define INF 800*1000
typedef pair<int, int>pii;
vector<pii>adj[805];

int dijkstra(int st, int en) {
	vector<int>mindist(805,INF);
	priority_queue < pii, vector<pii>, greater<pii>>pq;
	mindist[st] = 0;
	pq.push({ 0,st });

	while (!pq.empty()) {
		int cost = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		if (x == en) break;
		if (mindist[x] != cost) continue;
		for (int i = 0; i < adj[x].size(); i++)
		{
			int dist = adj[x][i].first;
			int nxt = adj[x][i].second;
			if (mindist[nxt] > cost + dist) {
				mindist[nxt] = cost + dist;
				pq.push({ mindist[nxt],nxt });
			}
		}

	}
	return mindist[en];
}


int main() {
	int n, e;
	scanf("%d%d", &n,&e);
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a,&b,&c);
		adj[a].push_back({ c,b });
		adj[b].push_back({ c,a });
	}
	int v1, v2;
	scanf("%d%d", &v1, &v2);

	int tmp1=dijkstra(1, v1);
	int tmp2=dijkstra(v1,v2);
	int tmp3=dijkstra(v2,n);
	int ans = tmp1 + tmp2 + tmp3;
	
	tmp1 = dijkstra(1, v2);
	tmp2 = dijkstra(v2, v1);
	tmp3 = dijkstra(v1, n);

	ans = min(ans, tmp1 + tmp2 + tmp3);

	if (ans >= INF) ans = -1;
	printf("%d", ans);
}
