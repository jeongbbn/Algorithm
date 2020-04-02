#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 10005
typedef pair<int, int> pi;
typedef pair<double, pair<int, int>> pii;

int n, m;
pi arr[1005];
vector<pii>adj;
vector<int>uf (1005, -1);

int find(int a) {
	if (uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

bool merge(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (x == y) return 0;

	if (uf[x] == uf[y]) uf[x]--;
	if (uf[x] < uf[y]) { uf[y] = x; }
	else { uf[x] = y; }
	return 1;
}


int main() {
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &arr[i].first, &arr[i].second);
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		merge(a, b);
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = i+1; j <= n; j++)
		{
			if (find(i) == find(j)) continue;
			double a1 = pow(arr[i].first - arr[j].first,2);
			double a2 = pow(arr[i].second - arr[j].second,2);
			double dist = sqrt(a1 + a2);
			adj.push_back({ dist,{i,j} });
		}
	}

	sort(adj.begin(), adj.end());

	int cnt = 0;
	double cost = 0;
	for (int i = 0; i < adj.size(); i++)
	{
		int u = adj[i].second.first;
		int v = adj[i].second.second;
		double dist = adj[i].first;
		if (!merge(u, v)) continue;
		cost += dist;
		cnt++;

		if (cnt == n - m) break;
	}

	printf("%.2f", cost);
}
