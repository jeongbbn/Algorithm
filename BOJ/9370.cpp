#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<set>
#include<map>
#include <string>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int n, m, k;
		scanf("%d%d%d", &n,&m,&k);

		int s, g, h;
		scanf("%d%d%d", &s,&g,&h);

		vector<pi>adj[2005];
		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			adj[a].push_back({ c,b });
			adj[b].push_back({ c,a });
		}

		vector<int>des;
		bool desti[2005] = { 0, };
		for (int i = 0; i < k; i++)
		{
			int a;
			scanf("%d", &a);
			desti[a] = 1;
		}

		int mindist[2005] = { 0, };
		for (int i = 1; i <= n; i++)
		{
			mindist[i] = INF;
		}
		mindist[s] = 0;

		priority_queue<pi, vector<pi>, greater<pi>>pq;
		pq.push({ 0,s });

		vector<int> prev[2005];

		while (!pq.empty()) {
			int cur = pq.top().second;
			int dist = pq.top().first;
			pq.pop();

			for (int i = 0; i < adj[cur].size(); i++)
			{
				int nxt = adj[cur][i].second;
				int cost = adj[cur][i].first;

				if (mindist[nxt] >= mindist[cur] + cost) {
					mindist[nxt] = mindist[cur] + cost;
					pq.push({ mindist[nxt], nxt });
					prev[nxt].push_back(cur);
				}
			}
		}

		for (int i = 1; i <= n; i++)
		{
			if (desti[i]) {
				if (mindist[i] == INF) desti[i] = 0;
			}
		}

		for (int i = 1; i <= n; i++)
		{
			bool flag = false;
			if (desti[i]) {
				int st = prev[i];
				while (st != s) {
					if (st == g || st == h) {
						flag = true;
					}
					st = prev[st];
				}
				if (!flag) desti[i] = 0;
			}
		}

		for (int i = 1; i <= n; i++)
		{
			if (desti[i]) printf("%d ", i);
		}
		printf("\n");

	}

}
