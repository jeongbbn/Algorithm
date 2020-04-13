#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<map>
#include <string>
using namespace std;
#define INF 800*1000
typedef pair<int, int>pii;

vector<pii>adj[100005];
int ans;
int bfs(int a) {
	vector<int>dist(100005, -1);
	queue<int>q;
	q.push(a);
	dist[a] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < adj[x].size(); i++)
		{
			int nx = adj[x][i].first;
			if (dist[nx] != -1) continue;
			dist[nx]= dist[x]+ adj[x][i].second;
			q.push(nx);
		}
	}

	int idx = max_element(dist.begin(), dist.end()) - dist.begin();
	ans = *max_element(dist.begin(), dist.end());
	return idx;
}

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++){
		int c;
		scanf("%d", &c);
		while (1) {
			int a, b;
			scanf("%d", &a);
			if (a == -1) break;
			scanf("%d", &b);
			
			adj[c].push_back({a,b});
		}
	}

	int v1 = bfs(1);
	bfs(v1);
	printf("%d", ans);

}
