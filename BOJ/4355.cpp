#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 100003
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

int t;
int main() {
	while (1) {
		ll n;
		scanf("%lld", &n);
		if (n == 0) break;

		ll pi = n;
		for (ll i = 2; i * i <= n; i++)
		{
			if (n % i == 0) {
				pi = pi * (i - 1) / i; //오일러 파이함수 n*(1-1/p)... == n*(p-1)/p
				while (n % i == 0) n /= i;
			}
		}
		if (n != 1) { //소인수가 남음
			pi = pi / n * (n - 1);
		}
		printf("%lld\n", pi);
	}
}4
