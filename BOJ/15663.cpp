#include <iostream>
#include <algorithm>
using namespace std;

int n, m, tmp[8],arr[8];
bool visit[9];

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

		bool flag=0;
		if (i == 0) flag = 1;
		else if (tmp[i] != tmp[i - 1]) flag = 1;

		if (!visit[x] && flag){
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
		scanf("%d", &tmp[i]);
	sort(tmp, tmp + n);
	f(0);
}
