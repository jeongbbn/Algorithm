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

int n, m;
vector<int>adj[20005];
int dist[20005];
queue<int>q;
void bfs(int st) {
	q.push(st);
	dist[st] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < adj[x].size(); i++)
		{
			int nx = adj[x][i];
			if (dist[nx]!=-1) continue;
			dist[nx] = dist[x] +1;
			q.push(nx);
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	fill(dist, dist + n + 1, -1);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	bfs(1);
	int cnt = 0;
	int minn = INF;
	int distt = *max_element(dist, dist + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == distt) { 
			minn = minn < i ? minn : i;
			cnt++; 
		}
	}
	printf("%d %d %d", minn,distt,cnt);
}
