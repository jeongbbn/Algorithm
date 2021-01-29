#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int main() {
	int n;
	scanf("%d", &n);

	int cnt = 0;
	for (int c = 1; c < n; c++)
	{
		if (c >= n - c) continue;
		for (int a = 1; a <= c; a++)
		{
			int b = n - c - a;
			if (b > 0 && b <= c && b <= a) { cnt++; }
		}
	}

	if (cnt == 0) printf("-1");
	else printf("%d", cnt);
}
