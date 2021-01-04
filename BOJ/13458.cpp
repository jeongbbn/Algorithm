#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;
typedef pair<int, pair<int, int>> pii;

int arr[1000005], n, b,c;
long long cnt;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d%d", &b, &c);

	cnt = n;
	for (int i = 0; i < n; i++) { arr[i] = max(arr[i] - b, 0); };

	for (int i = 0; i < n; i++)
	{
		cnt += arr[i] / c;
		if (arr[i] % c != 0) cnt++;
	}

	printf("%lld", cnt);
}	
