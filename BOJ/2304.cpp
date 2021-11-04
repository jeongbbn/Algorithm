#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int arr[1005];
int n, minn, maxx;
int ans;

void left(int st, int en) {
	if (en <= minn) return;
	int p = max_element(arr + st, arr + en) - arr;

	int height = *max_element(arr + st, arr + en);
	ans += height * (en - p);
	left(st, p);
}

void right(int st, int en) {
	if (st > maxx) return;
	int p = max_element(arr + st, arr + en + 1) - arr;

	int height = *max_element(arr + st, arr + en + 1);
	ans += height * (p - st + 1);
	right(p+1, en);
}

int main() {
	scanf("%d", &n);
	int maxH = -1, p;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a,&b);
		arr[a] = b;
		
		minn = min(a, minn);
		maxx = max(a, maxx);

		if (b > maxH) {
			maxH = b;
			p = a;
		}
	}

	ans = maxH;
	left(minn, p);
	right(p+1, maxx);

	printf("%d", ans);
}
