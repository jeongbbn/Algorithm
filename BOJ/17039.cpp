#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int a, b, c;

int main() {
	scanf("%d%d%d", &a, &b, &c);

	if (a + 2 == c) {
		printf("0\n0"); return 0;
	}
	else if (a + 2 == b || b + 2 == c) printf("1\n");
	else printf("2\n");
	printf("%d", max(b - a, c - b) - 1);
}
