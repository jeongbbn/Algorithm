#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000000
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

int n;
int tree[400005], ans[100005];

void update(int node, int st, int en, int idx, int diff) {
	if (idx < st || en < idx) return;
	tree[node] += diff;
	if (st != en) {
		int mid = (st + en) / 2;
		update(node * 2, st, mid, idx, diff);
		update(node * 2 + 1, mid + 1, en, idx, diff);
	}
}

int find(int node, int st, int en, int sum) {
	if (st == en) return st;
	int mid = (st + en) / 2;
	if (tree[2 * node] >= sum) return find(node * 2, st, mid, sum);
	else return find(node * 2 + 1, mid + 1, en, sum - tree[2 * node]);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) update(1, 1, n, i, 1);

	for (int i = 1; i <= n; i++)
	{
		int a;
		scanf("%d", &a);
		int p = find(1, 1, n, a + 1);
		ans[p] = i;
		update(1, 1, n, p, -1);
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n", ans[i]);
}
