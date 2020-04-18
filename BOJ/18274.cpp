#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
using namespace std;
#define INF 1e9+10

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);

		if (a < 12 || b<4) { printf("-1\n"); continue; }
		printf("%d\n", b * 11 + 4);
	}
}
