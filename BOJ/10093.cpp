#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long a, b, gap;
	scanf("%lld %lld", &a, &b);
	if (a > b) swap(a, b);

	if (a == b) gap = 0;
	else gap = b - a - 1;

	printf("%lld\n",gap);

	for (++a; a < b; a++)
		printf("%lld ", a);

	return 0;
}
