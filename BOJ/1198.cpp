#include <iostream>
#include <algorithm>
using namespace std;

int s, n, cnt, sum, arr[21];
void func(int k) {
	if (s == sum) cnt++;
	if (k == n) return;

	for (int i = k; i < n; i++)
	{
		sum += arr[i];
		func(i + 1);
		sum -= arr[i];
	}
}

int main() {
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	func(0);
	if (s == 0)	cnt -= 1;
	printf("%d", cnt);
}
