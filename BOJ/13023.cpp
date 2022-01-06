#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n, m;
bool visit[2005];
vector<int>adj[2005];
int cnt;
bool ans;

void dfs(int x, int c) {
	cnt = max(cnt, c);
	if (cnt >= 4) { 
		ans = 1; 
		return;
	}
	for (int i = 0; i < adj[x].size(); i++)
	{
		int nx = adj[x][i];
		if (!visit[nx]) {
			visit[nx] = 1;
			dfs(nx, c+1);
			visit[nx] = 0;
			if (ans) return;
		}
	}
	if (ans) return;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < n; i++)
	{
		visit[i] = 1;
		dfs(i, 0);
		if (ans) break;
		visit[i] = 0;
	}

	if (ans) printf("1");
	else printf("0");
}
