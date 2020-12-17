#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int d[45][3];
int main() {
	int n;
	scanf("%d", &n);
	int t;
	scanf("%d", &t);

	bool vip[45] = {0,};
	for (int i = 0; i < t; i++) {
		int a;
		scanf("%d", &a);
		vip[a] = 1;
	}

	d[1][0] = 0;
	d[1][1] = 1;
	d[1][2] = 1;

	if (vip[1] == 1) {
		d[1][0] = 0;
		d[1][2] = 0;
	}

	for (int i = 2; i <= n; i++)
	{
		d[i][0] = d[i-1][2];
		d[i][1] = d[i-1][0] + d[i-1][1];
		d[i][2] = d[i-1][0] + d[i-1][1];

		if (vip[i] == 1) {
			d[i][0] = 0;
			d[i][2] = 0;
		}
	}

	printf("%d", d[n][0] + d[n][1]);
}
