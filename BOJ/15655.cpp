#include <iostream>
#include <algorithm>
using namespace std;

int n, m,tmp[9],arr[9];
bool visit[10005];

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
	for (int i = 0; i < n; i++) //case 1 1 �� ��찡 �־ int i=1�̸� �ȵ�.
	{
		int x = tmp[i]; 
		if (x < flag) continue;
		if (!visit[x])
		{
			visit[x] = 1;
			arr[p] = x;
			f(p+1);
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
