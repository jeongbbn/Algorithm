#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;

int main() {
	int x, y, w, h;
	scanf("%d%d%d%d", &x, &y, &w, &h);

	int top = abs(h - y);
	int ans1 = min(top, y);

	int r = abs(w - x);
	int ans2 = min(r, x);

	int ans = min(ans1, ans2);
	printf("%d", ans);

}
