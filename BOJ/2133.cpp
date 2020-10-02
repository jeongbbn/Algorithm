#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
using namespace std;
#define INF 1e9+10

int d[35];

int main() {
	int n;
	scanf("%d", &n);

	d[0] = 1;
	d[2] = 3;
	d[4] = 11;

	for (int i = 6; i <= n; i+=2)
	{
		d[i] = d[i - 2] * 3;
		for (int j = 0; j <= i-4; j+=2)
			d[i] += d[j] * 2;
	}

	printf("%d", d[n]);
}
