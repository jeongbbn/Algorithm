#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int n, ans;
pi arr[100005];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		arr[i] = { -a + b, a + b };
	}
	sort(arr, arr + n);
	reverse(arr, arr + n);

	int y = arr[0].second;

	for (int i = 0; i < n; i++)
	{
		if (y < arr[i].second) { y = arr[i].second; ans++; }

	}
	printf("%d", ans + 1);
}
