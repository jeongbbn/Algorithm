#include <bits/stdc++.h>
using namespace std;

int n;
vector<int>adj[3005];
bool visit[3005];
bool cycles[3005];
int cycle;
bool flag;
void dfs(int x,int p) {
	if (visit[x]) {
		cycle = x;
		cycles[x] = 1;
		flag = 1;
		return;
	}

	visit[x] = 1;
	for (int i = 0; i < adj[x].size(); i++)
	{
		int nxt = adj[x][i];
		if (nxt == p) continue;
		dfs(nxt, x);
		if (flag && !cycles[x]) { cycles[x] = 1; return; }
	}
}

queue<int>q;
int dist[3005];
void bfs(int x) {
	q.push(x);
	dist[x] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < adj[now].size(); i++)
		{
			int nxt = adj[now][i];
			if (dist[nxt] >= 0) continue;
			if (cycles[nxt]) dist[nxt] = dist[now];
			else { dist[nxt] = dist[now] + 1; }
			q.push(nxt);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1,1);

	fill(dist + 1, dist + n + 1, -1);
	bfs(cycle);

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", dist[i]);
	}
}
