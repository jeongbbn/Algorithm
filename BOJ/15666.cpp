#include <iostream>
#include <algorithm>
using namespace std;

int n, m, tmp[8], arr[8];
bool used[8][10001];

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
		if (!used[p][x]) {
			used[p][x] = 1;
			arr[p] = x;
			f(p + 1);
		}
	}
	for (int i = 0; i < 10001; i++)
		used[p][i] = 0;

}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &tmp[i]);
	sort(tmp, tmp + n);
	f(0);
}
