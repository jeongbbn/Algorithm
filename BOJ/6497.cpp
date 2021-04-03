#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
using ti3 = tuple<int, int, int>;
vector<int>uf;
int find(int a) {
	if (uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

bool merge(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (x == y) return 0;

	if (uf[x] == uf[y]) uf[x]--;
	if (uf[x] < uf[y]) uf[y] = x;
	else uf[x] = y;
	return 1;
}

int main() {
	while (1) {
		int n, m;
		scanf("%d%d", &n,&m);
		if (n == 0 && m == 0) return 0;
		uf.resize(n,-1);
		vector<ti3>adj;
		int sum = 0;
		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			adj.push_back({ c,a,b });
			sum += c;
		}

		sort(adj.begin(), adj.end());

		int total = 0, cnt=0;
		for (int i = 0; i < m; i++)
		{
			int cost, v1, v2;
			tie(cost, v1, v2) = adj[i];
			if (!merge(v1, v2)) continue;
			total += cost;
			cnt++;
			if (cnt == n - 1) break;
		}
		int ans = sum - total;
		printf("%d\n", ans);
	}
}
