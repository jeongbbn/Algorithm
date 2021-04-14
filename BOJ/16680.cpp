#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;
typedef pair<int, pair<int, int>> pii;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		long long n;
		scanf("%lld", &n);

		while (n <= 1'000'000'000'000'000'000) {
			long long tmp = n;
			int sum = 0;
			while (tmp != 0) {
				sum += tmp % 10;
				tmp /= 10;
			}

			if (sum % 2 == 1) {
				printf("%lld\n", n); break;
			}
			else n += n;

			printf("         %d\n", n);
		}
	}
}
