#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int pre[1005], post[1005], idx[1005];
int p;

void func(int st, int en) {
	if (st > en) return;
	int root = pre[p++];

	func(st, idx[root] - 1);
	func(idx[root] + 1, en);
	printf("%d ",root);
}

int main() {
	int tc;
	scanf("%d", &tc);
	
	while (tc--) {
		int n;
		scanf("%d", &n);
		p = 0;

		for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
		for (int i = 0; i < n; i++) {
			scanf("%d", &post[i]);
			idx[post[i]] = i;
		}

		func(0, n - 1);
		printf("\n");
	}
}
