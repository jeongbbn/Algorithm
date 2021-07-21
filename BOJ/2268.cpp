#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<set>
#include<math.h>
#include<map>
#include <string>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

long long tree[4000001];
long long arr[1000005];

long long sum(int node, int l, int r, int st, int en) {
	if (r < st || en < l) return 0;
	if (l <= st && en <= r) return tree[node];
	int mid = (st + en) / 2;
	return sum(node*2, l, r, st, mid) + sum(node*2+1, l, r, mid + 1, en);
}

void update(int node, int st, int en, long long diff, int idx) {
	if (idx < st || en < idx) return;
	tree[node] += diff;
	if (st != en) {
		int mid = (st + en) / 2;
		update(node * 2, st, mid, diff, idx);
		update(node * 2+1, mid + 1, en, diff, idx);
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int a;
		scanf("%d", &a);

		if (a == 0) { 
			int b, c;
			scanf("%d%d", &b, &c);
			if (b > c) {
				int tmp = b;
				b = c;
				c = tmp;
			}
			printf("%lld\n", sum(1, b - 1, c - 1, 0, n - 1)); }
		else {
			int b;
			long long c;
			scanf("%d%lld", &b, &c);
			long long diff = c - arr[b - 1];
			arr[b - 1] = c;
			update(1, 0, n - 1, diff, b - 1);
		}
	}
}
