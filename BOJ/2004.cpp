#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n,m;
	scanf("%d%d", &n, &m);
	int k = n - m;

	int cnt2=0;
	for (long long i = 2; i <= n; i*=2)
		cnt2 += n / i;

	for (long long i = 2; i <= m; i *= 2)
		cnt2 -= m / i;

	for (long long i = 2; i <= k; i *= 2)
		cnt2 -= k / i;

	int cnt5 = 0;
	for (long long i = 5; i <= n; i *= 5)
		cnt5 += n / i;

	for (long long i = 5; i <= m; i *= 5)
		cnt5 -= m / i;

	for (long long i = 5; i <= k; i *= 5)
		cnt5 -= k / i;

	printf("%lld", min(cnt2,cnt5));
}
