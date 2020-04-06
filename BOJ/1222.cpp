#include <bits/stdc++.h>
using namespace std;
long long check[2000005];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);

		for (int j = 1; j*j <= a; j++)
		{
			if (a%j == 0) { //약수를 구함
				check[j]++;
				if (j*j == a) continue;
				check[a / j]++;
			}
		}
	}
	long long ans = -1;
	for (long long j = 1; j <= 2000000; j++)
	{
		if (check[j] == 0 || check[j] == 1) continue;
		ans = max(ans, j*check[j]); 
	}
	printf("%lld", ans);

}
