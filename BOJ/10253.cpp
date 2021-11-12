#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000000
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		ll a, b, x = 2;
		scanf("%lld%lld", &a, &b);

		while (1) {
			x = b / a;
			if (b%a != 0) x++;
			if (b == a * x) { printf("%lld\n", x); break; }
			a = a * x - b;
			b = b * x;
		}
	}
}
