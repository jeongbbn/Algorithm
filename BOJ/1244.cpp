#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int n, k;
bool arr[105];
void boy(int p) {
	for (int i = p; i <= n; i+=p)
	{
		arr[i] = !arr[i];
	}

}

void girl(int p) {
	arr[p] = !arr[p];
	for (int i = 1; p - i > 0 && p + i < n+1; i++)
	{
		if (arr[p - i] == arr[p + i]) {
			arr[p - i] = !arr[p - i];
			arr[p + i] = !arr[p + i];
		}
		else break;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		int a, b;
		scanf("%d%d", &a,&b);

		if (a == 1) boy(b);
		else girl(b);
	}

	int t = 1;
	while (t <= n) {
		int i;
		for (i = t; i < 20 + t; i++)
		{
			if (i >= n + 1)  break; 
			printf("%d ", arr[i]);
		}
		t = i;
		printf("\n");
	}

}
