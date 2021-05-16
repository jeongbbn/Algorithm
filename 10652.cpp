#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pi;

int b, e, p, n, m;
ll ans = 9987654321;
vector<int>adj[40005];
int visited[3][40005];

void bfs(int st) {
	queue<pi>q;
	q.push({ st, 1 });
	if (st == n) {
		st = 0;
		visited[0][n] = 0;
	}
	else visited[st][st] = 0;
		
	while (!q.empty()) {
		int x = q.front().first;
		int dist = q.front().second;
		q.pop();

		for (int i = 0; i < adj[x].size(); i++)
		{
			int nx = adj[x][i];
			if (visited[st][nx] >= 0) continue;
			visited[st][nx] = dist;
			q.push({ nx, dist + 1 });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> b >> e >> p >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < 3; i++)
		for (int j = 1; j <= n; j++)
			visited[i][j] = -1;

	bfs(1); bfs(2); 
	bfs(n);

	for (int i = 1; i <= n; i++)
	{
		ans = min(ans, (ll)(visited[1][i] * b) + (ll)(visited[2][i] * e)
			+ (ll)(visited[0][i] * p));
	}
	cout << ans;
}
