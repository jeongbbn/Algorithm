#include <iostream>
#include <algorithm>
using namespace std;

int n, m,arr[8],tmp[8];

void f(int p) {
	if (p == m) {
		for (int i = 0; i < m; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	int flag;
	if (p == 0) flag = tmp[0];
	else flag = arr[p - 1];

	for (int i = 0; i < n; i++)
	{
		int x = tmp[i];
		if (x < flag) continue;
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
