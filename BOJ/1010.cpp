#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
using namespace std;
#define INF 1e9+10

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		long long ans = 1;

		int k = min(n, m - n);
		for (int i = 0; i < k; i++)
		{
			ans *= m;
			m--;
		}
		long long div = 1;
		for (int i = 1; i <= k; i++)
		{
			div *= i;
		}
		printf("%lld\n", ans/div);
	}
}
