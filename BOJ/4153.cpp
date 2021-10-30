#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;

int main() {
	while (1) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (a == 0 && b == 0 && c == 0) break;
		a *= a; b *= b; c *= c;
		if (c == a + b) printf("right\n");
		else if (a == c + b) printf("right\n");
		else if (b == c + a) printf("right\n");
		else printf("wrong\n");
	}
}
