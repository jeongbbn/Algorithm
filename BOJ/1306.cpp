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
int arr[1000005];
int tree[3000000];

long long init(int node, int st, int en) {
	if (st == en) return tree[node] = arr[st];
	int mid = (st + en) / 2;
	return tree[node] = max(init(node * 2, st, mid), init(node * 2+1, mid+1, en));
}

long long find(int node, int l, int r, int st, int en) {
	if (r < st || en < l) return 0;
	if (l <= st && en <= r) return tree[node];
	int mid = (st + en) / 2;

	int v1 = find(node*2, l, r, st, mid);
	int v2 = find(node*2+1, l, r, mid + 1, en);
	return max(v1, v2);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	init(1, 0, n - 1);

	for (int i = m-1; i < n - m + 1; i++)
	{
		printf("%d ", find(1, i-m+1, i + m-1, 0, n - 1));
	}

}
