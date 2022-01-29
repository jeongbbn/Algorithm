#include <iostream>
#include <vector>
using namespace std;

int n, k,cnt;
vector<int>arr;
int main() {
	scanf("%d %d",&n, &k);
	arr.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = n-1; i >= 0; i--)
	{
		if (k < arr[i]) continue;
		cnt += k / arr[i];
		k = k % arr[i];
		if (k == 0)	break;
	}
	printf("%d", cnt);
}
