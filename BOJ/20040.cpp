#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 10007
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<int, pi>pii;

int n, m, ans;
vector<int>parent(500005, -1);

int find(int a) {
	if (parent[a] < 0) return a;
	return parent[a] = find(parent[a]);
}

bool merge(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (x == y) return 0;
	if (parent[x] == parent[y]) parent[x]--;

	if (parent[x] < parent[y]) parent[y] = x;
	else parent[x] = y;
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (ans != 0) continue;
		if (!merge(a, b)) ans = i;
	}
	cout << ans;
}
