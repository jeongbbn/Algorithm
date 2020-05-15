#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int main() {
	int n;
	scanf("%d", &n);

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		int leftover = b % a;
		sum += leftover;
	}
	printf("%d", sum);
	return 0;
}
