#include <iostream>
using namespace std;

int n,cnt;
bool sieve[4000005];
void isPrime() {
	for (int i = 2; i <= n; i++) sieve[i] = 1;

	for (int i = 2; i*i <= n; i++)
	{
		if (!sieve[i]) continue;
		for (int j = i*i; j <= n; j+=i)
		{
			sieve[j] = 0;
		}
	}
}
int idx[4000005];

int main() {
	scanf("%d", &n);
	isPrime();

	int st = 2, en = 3, sum = 2;
	int k = 2;
	while (st <= n) {

		if (sum < n) {
			sum += en;
			en++;
			while (!sieve[en]) en++;
		}
		else if(sum > n){
			sum -= st;
			st++;
			while (!sieve[st]) st++;
		}
		if (sum == n) {
			cnt++;
			sum -= st;
			st++;
			while (!sieve[st]) st++;
		}
		
	}
	printf("%d", cnt);
}
