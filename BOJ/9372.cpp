#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
using namespace std;
using ti3 = tuple<int, int, int>;
#define INF 1e9+10

int t;
int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int n, m;
		scanf("%d%d", &n,&m);
		vector<pair<int,int>>adj[1005];
		priority_queue<ti3,vector<ti3>,greater<ti3>>pq;
		for (int i = 0; i < m; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			adj[a].push_back({ 1,b });
			adj[b].push_back({ 1,a });
		}

		bool check[1005] = { 0, };
		for (int i = 0; i < adj[1].size(); i++)
		{
			pq.push({ adj[1][i].first,1,adj[1][i].second });
		}
		check[1] = 1;

		int cnt = 0, total=0;
		while (!pq.empty()) {
			int cost, v1, v2;
			tie(cost, v1, v2) = pq.top();
			pq.pop();

			if (check[v2]) continue;
			check[v2] = 1;
			cnt++;
			total += cost;

			if (cnt == n - 1) break;
			for (int i = 0; i < adj[v2].size(); i++)
			{
				int nxt = adj[v2][i].second;
				if (check[nxt]) continue;
				pq.push({ adj[v2][i].first,v2,nxt });
			}
		}

		printf("%d\n", total);
	}


}
