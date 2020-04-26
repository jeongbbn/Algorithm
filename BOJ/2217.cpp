#include <iostream>
#include <algorithm>
using namespace std;

int n,x,maax,arr[100001];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		x = arr[i] * (n - i);
		maax = maax > x ? maax : x;
	}
	printf("%d", maax);
}
