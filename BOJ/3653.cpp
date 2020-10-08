#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

int n, t, m;
int idx[100005];
vector<int>tree;
void update(int i, int diff) {
	while (i < tree.size()) {
		tree[i] += diff;
		i += (i&-i);
	}
}

int sum(int i) {
	int ret = 0;
	while (i > 0) {
		ret += tree[i];
		i -= (i&-i);
	}
	return ret;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		tree.clear();
		tree.resize(m + n + 1);
		fill(idx, idx + n + 1, 0);
		for (int i = 1, j = n; i <= n; i++, j--) {
			update(i, 1);
			idx[i] = j;
		}

		int p = n + 1;
		for (int i = 0; i < m; i++) {
			int a;
			scanf("%d", &a);
			printf("%d ", sum(m + n) - sum(idx[a]));
			update(idx[a], -1);
			update(p, 1);
			idx[a] = p++;
		}
		printf("\n");
	}
}
