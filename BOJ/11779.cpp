#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
using namespace std;
typedef pair<int, int>p;
#define INF 1e9+10
int n, m, st,en;
int mindist[1005];
int pre[1005];
vector<p>adj[1005];
priority_queue<p, vector<p>, greater<p>>pq;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a,&b,&c);
		adj[a].push_back({ c,b });
	}
	scanf("%d%d", &st,&en);

	for (int i = 1; i <= n; i++)
		mindist[i] = INF;

	mindist[st] = 0;

	pq.push({0,st});
	while (!pq.empty()) {
		int dist = pq.top().first;
		int idx = pq.top().second;
		pq.pop();

		if (mindist[idx] != dist) continue;

		for (int i = 0; i < adj[idx].size(); i++) {
			int cost = adj[idx][i].first;
			int nxt = adj[idx][i].second;

			if (mindist[nxt] > cost + dist) {
				mindist[nxt] = cost + dist;
				pq.push({ mindist[nxt] , nxt });
				pre[nxt] = idx;
			}
		}
	}
	printf("%d\n", mindist[en]);

	vector<int>ans;
	int cur = en;
	while (cur != st) {
		ans.push_back(cur);
		cur = pre[cur];
	}
	ans.push_back(cur);
	reverse(ans.begin(), ans.end());
		
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[i]);
	}
}
