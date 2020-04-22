#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<set>
#include<map>
#include <string>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n, m, k;
long long arr[100005];
long long tree[400000];

long long init(int node, int st, int en) {
	if (st == en) return tree[node] = arr[st];
	int mid = (st + en) / 2;
	return tree[node] = init(2 * node, st, mid) + init(2 * node + 1, mid + 1, en);
}

void update(int node, int st, int en, int idx, long long diff) {
	if (idx < st || en < idx)return;
	tree[node] += diff;
	if (st != en){
		int mid = (st + en) / 2;
		update(node*2,st,mid,idx,diff);
		update(node*2+1,mid+1,en,idx,diff);
	}
}

long long sum(int node, int l, int r, int st, int en) {
	if (r < st || en < l) return 0;
	if (l <= st && en <= r)return tree[node];
	int mid = (st + en) / 2;
	return sum(node * 2, l,r, st, mid) + sum(node * 2 + 1, l,r, mid + 1, en);
}


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	init(1, 0, n - 1);
	for (int i = 0; i < m; i++)
	{
		int x, y, a;
		long long b;

		scanf("%d%d%d%lld", &x, &y, &a, &b);
		if (x > y) swap(x, y);
		printf("%lld\n", sum(1, x - 1, y - 1, 0, n-1));

		long long diff = b - arr[a - 1];
		update(1, 0, n-1, a - 1, diff);
		arr[a - 1] = b;
	}


}
