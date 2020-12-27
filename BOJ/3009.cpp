#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;

int main() {
	int a, b, c, d, e, f;
	scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
		
	int x, y;
	if (a == c && b == f) {
		x = e; y = d;
	}
	else if (b == d && a == e) {
		x = c; y = f;
	}
	else if (f == d && a == e) {
		x = c; y = b;
	}
	else if (c == e && f == b) {
		x = a; y = d;
	}
	else if (a == c && d == f) {
		x = e; y = b;
	}
	else if (c == e && d == b) {
		x = a; y = f;
	}

	printf("%d %d", x, y);

}
