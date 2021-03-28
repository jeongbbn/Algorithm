#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include <string>
#include<map>
#include<stack>
using namespace std;
#define INF 1e9+10
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
typedef pair<int, int>p;
//bool outrange(int x, int y) {
//	if (x < 0 || y < 0 || x >= n || y >= m) return 1;
//	return 0;
//}

int n, m;
vector<int>adj[1005];
bool visit[1005];
queue<int>q;
stack<int>s;
void bfs(int st) {
	q.push(st);
	visit[st] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < adj[x].size(); i++)
		{
			int nx = adj[x][i];
			if (visit[nx]) continue;
			visit[nx] = 1;
			q.push(nx);
		}
	}
}

void dfs(int st) {
	s.push(st);
	visit[st] = 1;
	while (!s.empty()) {
		int x = s.top();
		s.pop();
		for (int i = 0; i < adj[x].size(); i++)
		{
			int nx = adj[x][i];
			if (visit[nx]) continue;
			visit[nx] = 1;
			s.push(nx);
		}
	}
}

void dfs_r(int st) {
	visit[st] = 1;
	for (int i = 0; i < adj[st].size(); i++)
	{
		int nxt = adj[st][i];
		if (!visit[nxt]) {
			visit[nxt] = 1;
			dfs_r(nxt);
		}
	}

}

int main() {
	scanf("%d%d", &n,&m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!visit[i]) {
			dfs_r(i);
			cnt++;
		}
	}
	printf("%d", cnt);
}
