#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n, st;
vector<int>adj[100005];
int ans[100005];
int idx[100005]; //parent �ε���
pi chk[100005];
queue<pi>q;
bool visit[100005];

void bfs(int st) {
	q.push({ st, 0 });
	visit[st] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int dist = q.front().second;
		q.pop();

		for (int i = 0; i < adj[x].size(); i++)
		{
			int nx = adj[x][i];
			if (visit[nx]) continue;
			q.push({ nx,dist + 1 });
			chk[nx] = { dist + 1, idx[x] };
			visit[nx] = 1;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &ans[i]);
		idx[ans[i]] = i;
	}

	st = 1;
	bfs(st);

	for (int i = 0; i < n - 1; i++)
	{
		if (chk[ans[i]].first != chk[ans[i + 1]].first && chk[ans[i]].first + 1 != chk[ans[i + 1]].first) {
			printf("0");
			return 0;
		}

		if (chk[ans[i]].first == chk[ans[i + 1]].first && chk[ans[i]].second > chk[ans[i + 1]].second) {
			printf("0");
			return 0;
		}
	}
	printf("1");
}
