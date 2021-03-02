#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000000
typedef pair<string, bool>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int n, arr[505], dp[505];

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		
		int x = n * n;
		string a, b;
		a = to_string(n);
		b = to_string(x);

		int bp = b.size();
		int ap = a.size();
		bp--;

		int cnt = 0;
		for (int i = ap - 1; i >= 0; i--, bp--)
		{
			if (a[i] != b[bp]) break;
			cnt++;
		}

		if (cnt == ap) printf("YES\n");
		else printf("NO\n");
	}
	
}
