#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<ll, pi>pii;
#define INF 1e12
#define MAX 17

int N, q, depth[40005], s[40005][MAX], dist[40005];
vector<pi>adj[40005];
bool visited[40005];

/*
tree dfs 돌릴 때, dist[x]는 -1 이면 안된다고 생각해서 돌렸는데
이러니까 틀리더라, 귀찮더라도 visted배열을 만들어서 넣어주자.

*/
void dfs(int x, int sum, int deep) {
	depth[x] = deep;
	dist[x] = sum;
	visited[x] = 1;

	for (int i = 0; i < adj[x].size(); i++)
	{
		int nxt = adj[x][i].first;
		int cost = adj[x][i].second;
		
		if (visited[nxt]) continue;
		s[nxt][0] = x;
		dfs(nxt, sum + cost, deep + 1);
	}
}

int LCA(int a, int b) {
	if (depth[a] > depth[b]) swap(a, b);

	//높이를 맞춰준다.
	for (int i = MAX - 1; i >= 0; i--)
	{
		if (depth[b] - depth[a] >= (1 << i)) b = s[b][i];
	}

	if (a != b) {
		for (int i = MAX - 1; i >= 0; i--)
		{
			if (s[a][i] != s[b][i]) {
				a = s[a][i];
				b = s[b][i];
			}
		}
		a = s[a][0];
	}
	return a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}

	dfs(1, 0, 0);

	for (int j = 1; j < MAX; j++)
		for (int i = 1; i <= N; i++)
			s[i][j] = s[s[i][j - 1]][j - 1];

	cin >> q;
	while (q--) {
		int a, b; cin >> a >> b;
		int lca = LCA(a, b);

		cout << dist[a] + dist[b] - (dist[lca] * 2) <<  "\n";
	}

	return 0;
}
