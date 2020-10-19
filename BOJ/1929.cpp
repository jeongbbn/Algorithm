#include <iostream>
using namespace std;
#define MAX 10000001
int m, n;
bool sieve[MAX];

int main() {
	scanf("%d%d", &m, &n);
	for (int i = 2; i < MAX; i++)
		sieve[i] = 1;

	for (int i = 2; i*i <= n; i++)
	{
		if (!sieve[i]) continue;
		for (long long j = i * i; j <= n; j += i)
			sieve[j] = 0;
	}

	for (int i = m; i <= n; i++)
		if (sieve[i]) printf("%d\n", i);
}
