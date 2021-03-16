#include<bits/stdc++.h>
using namespace std;
#define INF 98765421
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;


int n, indegree[1005];
vector<int>v, adj[1005];
queue<int>q1, q2;
bool visited[1005];

void dfs(int x) {
	for (int i = 0; i < adj[x].size(); i++)
	{
		int nx = adj[x][i];
		if (visited[nx]) continue;
		visited[nx] = 1;
		dfs(nx);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		int l = INF, r = INF, a = 0;
		if (i - 1 >= 0) l = abs(v[i] - v[i - 1]);
		if (i + 1 < n) r = abs(v[i + 1] - v[i]);

		if (l <= r) a = v[i - 1];
		else a = v[i + 1];

		adj[v[i]].push_back(a);
		indegree[a]++;
	}

	for (int i = 0; i < n; i++) {
		if (indegree[v[i]] == 0) q1.push(v[i]);
		else q2.push(v[i]);
	}

	int ans = q1.size();
	while (!q1.empty()) {
		int x = q1.front(); q1.pop();
		visited[x] = 1; dfs(x);
	}

	while (!q2.empty()) {
		int x = q2.front(); q2.pop();
		if (visited[x]) continue;
		visited[x] = 1; dfs(x);
		ans++;
	}

	cout << ans;
}
