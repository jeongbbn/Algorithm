#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;
typedef pair<int, pair<int, int>> pii;

int n, m;
vector<int>adj[10005];
int dfsn[10005],dfsCnt;
int low[10005];
int parent[10005];

 int dfs(int curr, int p) {
	low[curr] = dfsn[curr] = ++dfsCnt;
	parent[curr] = p;
	for (int i = 0; i < adj[curr].size(); i++)
	{
		int next = adj[curr][i];

		if (next == p) continue;

		if (!dfsn[next]) {
			parent[next] = curr;
			dfs(next, curr);
			low[curr] = min(low[curr], low[curr]);
			continue;
		}
	}
}


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		if (!dfsn[i]) dfs(i, true);
	}

}
