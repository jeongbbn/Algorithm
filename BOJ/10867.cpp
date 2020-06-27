#include <iostream>
#include <algorithm>
using namespace std;

int check[2001], n, x;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		check[x]++;
	}
	for (int i = 0; i < n; i++)
	{
		if (check[i] > 0)
			printf("%d ", i);
	}
	return 0;
}
