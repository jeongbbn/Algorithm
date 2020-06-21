#include <iostream>
#include <algorithm>
using namespace std;

int n, m, arr[8],temp[8];
bool visit[10001];

void f(int p) {
	if (p == m) {
		for (int i = 0; i < m; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for (int i = 0; i < n; i++)
	{
		int x = temp[i];
		if (!visit[x])
		{
			visit[x] = 1;
			arr[p] = x;
			f(p + 1);
			visit[x] = 0;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &temp[i]);
	sort(temp, temp + n);
	f(0);
}
