#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;

int n, q;
vector<int>parent(200'005, -1);

int find(int a) {
	if (parent[a] < 0) return a;
	return parent[a] = find(parent[a]);
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
	}



	return 0;
}
