#include <iostream>
using namespace std;

int n, m, arr[8];
void func(int p) {
	if(p==m){
		for (int i = 0; i < m; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		arr[p] = i;
		func(p+1);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	func(0);
}
