#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n, m, sett = INF, unit = INF;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		unit = min(unit, b);
		sett = min(sett, a);
	}

	int cost = 0;
	while (n) {
		if (n >= 6) {
			if (sett > unit * 6) cost += unit * 6;
			else cost += sett;
			n -= 6;
		}
		else {
			if (sett > unit * n) cost += unit * n;
			else cost += sett;
			n -= n;
		}
	}
	printf("%d", cost);
}
