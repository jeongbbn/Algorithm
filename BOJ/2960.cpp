#include <iostream>
using namespace std;

bool sieve[1005];

int main() {
	int n, k, cnt=0;
	scanf("%d%d", &n, &k);

	for (int i = 2; i <= n; i++) sieve[i] = 1;

	for (int i = 2; i <= n; i++)
	{
		if (!sieve[i]) continue;
		for (int j = i*i; j <= n; j+=i)
		{
			sieve[j] = 0;
			cnt++;
			if (cnt == k) {
				printf("%d", j);
				return 0;
			}
			
		}
	}
}
