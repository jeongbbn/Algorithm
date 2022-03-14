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

int arr[1000005];
long long tree[4000005];
void update(int node, int st, int en, int idx, long long diff) {
	if (idx < st || en < idx) return;
	tree[node] += diff;
	if (st != en) {
		int mid = (st + en )/ 2;
		update(node * 2, st, mid, idx, diff);
		update(node * 2+1, mid+1, en, idx, diff);
	}
}

long long find(int node, int l, int r, int st, int en) {
	if (r < st || en < l)return 0;
	if (l <= st && en <= r) return tree[node];
	int mid = (st + en) / 2;
	return find(node * 2, l, r, st, mid) + find(node * 2 + 1, l, r, mid + 1, en);
}

int main() {
	int n, q;
	scanf("%d%d", &n,&q);
	for (int i = 0; i < q; i++)
	{
		int a;
		scanf("%d", &a);
		if (a == 1) {
			int b;
			long long c;
			scanf("%d%lld", &b, &c);
			update(1,0,n-1,b - 1, c);
		}
		else {
			int b, c;
			scanf("%d%d", &b, &c);
			printf("%lld\n", find(1,b-1,c-1,0,n-1));
		}
	}
	
	return 0;
}
