#include <iostream>
using namespace std;

#define MAX 10000000
bool isprime[MAX+5];
int main() {
	long long  a, b;
	scanf("%lld%lld", &a,&b);

	for (int i = 2; i <= MAX; i++)	isprime[i] = 1;

	for (int i = 2; i*i <= MAX; i++)
	{
		if (!isprime[i]) continue;
		for (int j=i*i; j <= MAX ; j+=i)
		{
			isprime[j] = 0;
		}
	}

	long long cnt = 0;
	for (int i = 2; i <= MAX; i++)
	{
		if (!isprime[i]) continue;
		long long n = i;
		while (n <= b / i) {
			if (n*i >= a) cnt++;
			n *= i;	
		}
	}

	printf("%lld", cnt);
}
