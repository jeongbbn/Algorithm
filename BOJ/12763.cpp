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


int n, t, m;
vector<pii>adj[105];
vector<pi>mindist[105];
int pre[105];
queue<pii>pq;

int main() {
	scanf("%d%d%d", &n, &t, &m);
	int l;
	scanf("%d", &l);
	for (int i = 0; i < l; i++) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a,&b,&c,&d);	
		adj[a].push_back({ b,{c,d}});
		adj[b].push_back({ a,{c,d}});
	}
	mindist[0].push_back({ 0,0 });
	mindist[1].push_back({ 0,0 });
	for (int i = 2; i <= n; i++)
	{
		mindist[i].push_back({ INF,INF });
	}
	pq.push({ 0,{0,1} });

	while (!pq.empty()) {
		int cur = pq.front().second.second;
		int cost = pq.front().second.first;
		int time = pq.front().first;
		pq.pop();

		for (int i = 0; i < adj[cur].size(); i++)
		{
			int nxt = adj[cur][i].first;
			int nxtcost = adj[cur][i].second.second;
			int nxttime = adj[cur][i].second.first;

			if (t >= time + nxttime && m>=cost + nxtcost) {
				mindist[nxt].push_back({ time + nxttime, cost + nxtcost });
				pq.push({ time + nxttime,{cost+nxtcost,nxt} });
			}
		}
	}
	int minn = INF;
	for (int i = 0; i < mindist[n].size(); i++)
	{
		minn = min(mindist[n][i].second, minn);
	}
	if (minn == INF) minn = -1;

	printf("%d", minn);
	
}
