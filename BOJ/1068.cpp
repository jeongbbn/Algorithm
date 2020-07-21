#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, pair<int, int>>pii;

int d, cnt;
vector<int>adj[55];
int n, parent[55];
int root, rcnt;

void dfs(int now, int par) {
	if (adj[now].size() == 0) {
		cnt++;
		return;
	}
	for (int i = 0; i < adj[now].size(); i++)
	{
		int nxt = adj[now][i];
		if (nxt == par) continue;
		if (nxt == d) { if (adj[now].size() == 1) cnt++;  continue; }
		dfs(nxt, now);
	}
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &parent[i]);
		if (parent[i] == -1) { root = i;  continue; }
		adj[parent[i]].push_back(i);
	}
	scanf("%d", &d);

	dfs(root, -1);
	if (d == root) cnt = 0;
	printf("%d", cnt);
}
