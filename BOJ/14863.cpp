#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;
typedef pair<int, pair<int, int>> pii;

int n, k;
queue<pii>q;
vector<pi>adj[105];
int mindist[105][100005];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		int a, b, c, d;
		scanf("%d %d%d%d", &a, &b, &c, &d);
		adj[i].push_back({ a,b });
		adj[i].push_back({ c,d });
	}

	for (int i = 0; i <= n; i++)
		for (int j = 0; j < 100005; j++)
			mindist[i][j] = -1;

	mindist[0][0] = 0;

	q.push({ 0,{ 0,0 } });
	while (!q.empty()) {
		int time = q.front().second.first;
		int cost = q.front().second.second;
		int now = q.front().first;
		q.pop();

		if (mindist[now][time] > cost) continue;
		for (int i = 0; i < 2; i++)
		{
			int nxttime = adj[now][i].first;
			int nxtcost = adj[now][i].second;

			if (k >= time + nxttime) {
				mindist[now+1][time+nxttime] = max(mindist[now+1][time + nxttime],cost + nxtcost);
				if (now != n - 1) {
					q.push({ now + 1,{time + nxttime, cost + nxtcost} });
				}
			}
		}
	}

	printf("%d", *max_element(mindist[n],mindist[n]+100005));
}
