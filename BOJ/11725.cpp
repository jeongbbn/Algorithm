
#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include <string>
#include<map>
#include <algorithm>
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

int parent[100005];
vector<int>adj[100005];
int n;
queue<int>q;
void bfs(int a) {
	q.push(a);
	parent[a] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < adj[x].size(); i++)
		{
			int nxt = adj[x][i];
			if (parent[nxt] != -1) continue;
			parent[nxt] = x;
			q.push(nxt);
		}
	}
}

int main() {
	scanf("%d", &n);
	fill(parent, parent + n + 1, -1);
	for (int i = 0; i < n-1; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	bfs(1);
	for (int i = 2; i <= n; i++)
	{
		printf("%d\n", parent[i]);
	}
}
