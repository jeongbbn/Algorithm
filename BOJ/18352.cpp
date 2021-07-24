#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int>pi;

int n, m, k, x;
vector<int>adj[300005];
bool visited[300005];
priority_queue<int, vector<int>, greater<int>>pq;

void bfs(int sx) {
	queue<pi>q;
	q.push({ sx,0 });
	visited[sx] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int dist = q.front().second;
		q.pop();

		if (dist == k) {
			pq.push(x);
			continue;
		}

		for (int i = 0; i < adj[x].size(); i++)
		{
			int nxt = adj[x][i];
			if (visited[nxt]) continue;
			visited[nxt] = 1;
			q.push({ nxt, dist + 1 });
		}

	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k >> x;
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
	}

	bfs(x);

	if (pq.size() == 0) cout << "-1";
	else {
		while (!pq.empty()) {
			cout << pq.top() << "\n";
			pq.pop();
		}
	}
}
