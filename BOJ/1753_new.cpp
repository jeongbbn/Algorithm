#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define	INF 1e9
typedef pair<int, int>pi;

int v, e, st;
vector<pi>adj[20005];
vector<int>minDist (20005, INF);
priority_queue<pi, vector<pi>, greater<pi>> pq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> v >> e >> st;

	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
	}

	minDist[st] = 0;
	pq.push({ minDist[st], st });

	while (!pq.empty()) {
		int dist = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		if (dist != minDist[x]) continue;

		for (int i = 0; i < adj[x].size(); i++)
		{
			int cost = adj[x][i].first;
			int nxt = adj[x][i].second;

			if (minDist[nxt] > dist + cost) {
				minDist[nxt] = dist + cost;
				pq.push({ minDist[nxt], nxt });
			}
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if (minDist[i] == INF) cout << "INF";
		else cout << minDist[i];
		cout << "\n";
	}
}
