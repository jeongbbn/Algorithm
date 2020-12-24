#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;
typedef pair<int, pair<int, int>> pii;

int arr[100005];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int maxx = arr[n - 1];
	int cnt = 1;
	for (int i = n-2; i >= 0; i--)
	{
		if (maxx < arr[i]) { cnt++; maxx = arr[i]; }
	}
	printf("%d", cnt);
}
