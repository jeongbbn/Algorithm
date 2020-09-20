#include <iostream>
using namespace std;

int m,arr[4];

int main() {
	arr[1] = 1;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int x, y,tmp;
		scanf("%d%d", &x, &y);
		tmp = arr[x];
		arr[x] = arr[y];
		arr[y] = tmp;
	}
	for (int i = 0; i < 4; i++)
		if (arr[i] == 1) printf("%d", i);
	
	return 0;
}
