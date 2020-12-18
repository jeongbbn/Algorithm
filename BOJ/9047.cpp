#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int n, T;
int arr[5];

int f(int c, int t) {
	for (int i = 0; i < 4; i++, t/=10) arr[i] = t % 10;
	sort(arr, arr + 4);
	int a = arr[3] * 1000 + arr[2] * 100 + arr[1] * 10 + arr[0];
	int b = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
	if (a - b == 6174) return c + 1;
	else return f(c + 1, a - b);
}

int main() {
	scanf("%d", &T);

		while (T--) {
		scanf("%d", &n);
		if (n == 6174) printf("0\n");
		else printf("%d\n", f(0, n));
	}
}
