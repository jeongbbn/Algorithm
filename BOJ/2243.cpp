#include <iostream>
#include <algorithm>
using namespace std;

int n,x,maax,arr[100001];#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000000
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int tree[4000006];
void update(int node, int st, int en, int idx, int diff) {
	if (idx < st || en < idx) return;
	tree[node] += diff;
	if (st != en) {
		int mid = (st + en) / 2;
		update(2 * node, st, mid, idx, diff);
		update(2 * node + 1, mid + 1, en, idx, diff);
	}
}

int find(int node, int st, int en, int sum) {
	if (tree[node] < sum) return -1;
	if (st == en) return st;
	int mid = (st + en) / 2;
	if (tree[node * 2] >= sum) return find(node * 2, st, mid, sum);
	else return find(node * 2 + 1, mid + 1, en, sum - tree[node * 2]);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		if (a == 1) {
			int b;
			scanf("%d", &b);
			int ans = find(1, 1, MAX, b);
			if (ans == -1) continue;
			printf("%d\n", ans);
			update(1, 1, MAX, ans, -1);
		}
		else {
			int b, c;
			scanf("%d%d", &b, &c);
			update(1, 1, MAX, b, c);
		}
	}
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		x = arr[i] * (n - i);
		maax = maax > x ? maax : x;
	}
	printf("%d", maax);
}
