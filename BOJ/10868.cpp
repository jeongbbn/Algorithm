#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<map>
#include <string>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int arr[100005];
int tree[300000];

long long init(int node,int st, int en) {
	if (st == en) return tree[node] = arr[st];
	int mid = (st + en) / 2;
	return tree[node] = min(init(node * 2, st, mid),init(node * 2 + 1, mid + 1, en));
}

long long find(int node, int l, int r, int st, int en) {
	if (l > en || r < st) return INF;
	if (l <= st && en <= r) return tree[node];
	int mid = (st + en) / 2;
	return  min(find(node * 2, l, r, st, mid), find(node * 2 + 1, l, r,mid + 1, en));
}



int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	init(1,0,n-1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);

		printf("%d\n", find(1, a-1, b-1, 0, n - 1));
	}


}
