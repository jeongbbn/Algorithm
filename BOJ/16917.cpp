#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int x, y, a, b, c;
int ans;
int main() {
	scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
	c *= 2;
	if (c <= a + b) {
		ans = c * min(x, y);
		if (x > y) {
			if(a < c) ans += a * (x - y);
			else ans += c * (x - y);
		}
		else 
			if (b < c) ans += b * (y - x);
			else ans += c * (y - x);
	}
	else {
		ans += a * x;
		ans += b * y;
	}
	printf("%d", ans);
}
