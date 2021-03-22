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

int n, m,k;

int arr[10005];
vector<int>parent(10005, -1);

int find(int a) {
	if (parent[a] < 0) return a;
	return parent[a] = find(parent[a]);
}

bool merge(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (x == y) return 0;
	if (parent[x] <= parent[y]) parent[x] = y;
	else parent[y] = x;
	return 1;
}


int main() {
	scanf("%d%d%d", &n, &m,&k);
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		parent[i] = -a;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (!merge(a, b)) continue;

	}

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (parent[i] < 0) sum += -parent[i];
	}

	if (sum > k) printf("Oh no");
	else printf("%d", sum);
}
