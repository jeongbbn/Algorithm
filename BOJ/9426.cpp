#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define N 65536
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

int n, k;
int arr[250005];
int tree[280005];
ll sum;

void update(int node, int st, int en, int idx, int diff) {
	if (idx < st || en < idx) return;
	tree[node] += diff;
	if (st != en) {
		int mid = (st + en) / 2;
		update(node * 2, st, mid, idx, diff);
		update(node * 2 + 1, mid+1, en, idx, diff);
	}
}

int count(int node, int st, int en, int flag) {
	if (st == en) return st;
	int mid = (st + en) / 2;
	if (tree[2 * node] >= flag) return count(node * 2, st, mid, flag);
	else return count(node * 2 + 1, mid + 1, en, flag - tree[2 * node]);
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		update(1, 0, N, arr[i], 1);
		if (i < k - 1) continue;
		else if (i == k - 1) {
			sum += count(1, 0, N, (k + 1) / 2);
			continue;
		}
		update(1, 0, N, arr[i - k], -1);
		sum += count(1, 0, N, (k + 1) / 2);
	}
	printf("%lld", sum);
	
}
