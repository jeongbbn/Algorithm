#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int n, tree[4000005], N, maxx, leaf;
ll ans;

int find(int node, int st, int en) {
	if (st == en) return tree[node];
	int mid = (st + en) / 2;

	int l = find(node * 2, st, mid);
	int r = find(node * 2 + 1, mid + 1, en);

	int maxx = max(l, r);
	tree[node * 2] += maxx - l;
	tree[node * 2 + 1] += maxx - r;
	return maxx + tree[node];
}

int main() {
	scanf("%d", &n);
	N = (1 << (n + 1)) - 1;
	leaf = 1 << n;
	for (int i = 2; i <= N; i++)
	{
		scanf("%d", &tree[i]);
	}

	find(1, 1, leaf);

	for (int i = 2; i <= N; i++)
	{
		ans += tree[i];
	}

	printf("%lld", ans);
}
