#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int t, sx, sy, dx, dy;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &sx, &sy, &dx, &dy);
		int n, ans = 0;
		scanf("%d", &n);
		while (n--) {
			int a, b, r;
			scanf("%d%d%d", &a, &b, &r);
			bool flag1 = 0, flag2 = 0;
			if ((pow((a - sx), 2) + pow((b - sy), 2)) < pow(r,2)) flag1 = 1;
			if ((pow((a - dx), 2) + pow((b - dy), 2)) < pow(r,2)) flag2 = 1;

			if (flag1 && flag2) continue;
			else if (!flag1 && !flag2) continue;
			else ans++;
		}
		printf("%d\n", ans);
	}
}
