#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int n, ans;
int arr[105];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int p = n - 1;
	while (p > 0) {
		if (arr[p] < arr[p - 1]) break;
		p--;
	}

	printf("%d", p);
}
