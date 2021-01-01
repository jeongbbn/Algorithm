#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, pair<int, int>>pii;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int h, w, n;
		scanf("%d%d%d", &h, &w, &n);
		int f, s = 0, t = 1;

		if (n % h == 0) {
			f = h;
			t += n / h -1;
		}
		else {
			f = n % h;
			t += n / h;
		}

		if (t < 10) printf("%d%d%d\n", f, s, t);
		else printf("%d%d\n", f, t);
	}
}
