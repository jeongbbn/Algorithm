#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
using namespace std;
#define INF 1e9+10

bool prime[2500001];
void isPrime() {
	for (int i = 2; i <= 2500000; i++)
		prime[i] = 1;

	for (int i = 2; i*i <= 2500000; i++)
	{
		if (!prime[i]) continue;
		for (int j = i * i; j <= 2500000; j += i)
		{
			prime[j] = 0;
		}
	}
}
int n;
int main() {
	isPrime();
	while (1) {
		scanf("%d", &n);
		if (n == 0) return 0;

		int cnt = 0;
		for (int i = n+1; i <= 2 * n; i++)
		{
			if (!prime[i]) continue;
			cnt++;
		}
		printf("%d\n", cnt);
	}
}
