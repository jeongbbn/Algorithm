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

bool ans[100005];
pi arr[100005];
vector<int>uf(100005, -1);

int find(int a) {
	if (uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

long long merge(int a, int b) {
	int x = find(a);
	int y = find(b);

	int v1 = uf[x];
	int v2 = uf[y];

	if (x == y) return 0;
	
	if (uf[x] <= uf[y]) {
		uf[x] += uf[y];
		uf[y] = x;
	}
	else {
		uf[y] += uf[x];
		uf[x] = y;
	}
	return (v1 * v2);
}


int main() {
	int n,m,q;
	scanf("%d%d%d", &n,&m,&q);

	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &arr[i].first, &arr[i].second);
	}
	int query[100005];
	for (int i = 0; i < q; i++)
	{
		scanf("%d", &query[i]);
		ans[query[i]] = 1;
	}
	reverse(query, query + q);

	for (int i = 1; i <= m; i++) {
		if (ans[i]) continue;
		merge(arr[i].first, arr[i].second);
	}

	long long sum = 0;
	for (int i = 0; i < q; i++) {
		sum += merge(arr[query[i]].first, arr[query[i]].second);
	}

	printf("%lld", sum);
}
