  #include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include <string>
#include<map>
#include <algorithm>
#include<stack>
using namespace std;
#define INF 1e9+10

int t;
int main() {
	scanf("%d", &t);
for (int i = 0; i < t; i++)
	{
		long long a, b;
		scanf("%d%d", &a, &b);
		long long gap = b - a;

		long long n = 1;
		while (1) {
			if (n*(n + 1) > gap) break;
			n++;
		}
		n = n - 1;

		long long cnt = n * 2;
		long long lefts = gap - n * (n + 1);
		if (lefts % (n + 1) != 0) cnt += 1;
		cnt += (lefts / (n + 1));

		printf("%lld\n", cnt);
	}
}
