#include <iostream>
#include <algorithm>
using namespace std;

int n, m, tmp[7],arr[7];

void f(int p) {
	if (p == m) {
		for (int i = 0; i < m; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for (int i = 0; i < n; i++)
	{
		int x = tmp[i];
		arr[p] = x;
		f(p + 1);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &tmp[i]);
	sort(tmp, tmp + n);
	f(0);
}
