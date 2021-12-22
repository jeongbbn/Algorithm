#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
using namespace std;
#define INF 1e9+10
int v, e, st;
int mindist[20005];
vector<pair<int, int>>adj[20005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
int main() {
	scanf("%d%d", &v, &e);
	scanf("%d", &st);

	for (int i = 1; i <= v; i++)
	{
		if (i == st) mindist[i] = 0;
		else mindist[i] = INF;
	}

	for (int i = 1; i <= v; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b,&c);
		adj[a].push_back({ c,b });
	}

	pq.push({ 0,1 });

	while (!pq.empty()) {
		auto now = pq.top();
		pq.pop();
		int idx = now.second;
		int dist = now.first;
		if (mindist[idx] != dist) continue;

		for (int i = 0; i < adj[idx].size(); i++)
		{
			int cost = adj[idx][i].first;
			int nxt = adj[idx][i].second;

			if (mindist[nxt] > cost + dist) {
				mindist[nxt] = cost + dist;
				pq.push({ mindist[nxt] ,nxt });
			}

		}
	}
	for (int i = 1; i <= v; i++)
	{
		if (mindist[i] == INF) printf("INF\n");
		else printf("%d\n", mindist[i]);
	}
}
