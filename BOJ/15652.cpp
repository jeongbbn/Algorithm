#include <iostream>
using namespace std;

int n, m,arr[9];

void f(int p) {
	if (p == m) {
		for (int i = 0; i < m; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	int flag;
	if (p == 0) flag = 1;
	else flag = arr[p - 1];

	for (int i = flag; i <= n; i++)
	{
		arr[p] = i;
		f(p + 1);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	f(0);
}
