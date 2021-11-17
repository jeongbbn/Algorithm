#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

vector<int>f;
int main() {
	int tc;
	scanf("%d", &tc);
	f.push_back(0); f.push_back(1);
	for (int i = 2; i <= 1000000000; i++)
	{
		f.push_back(f[i - 1] + f[i - 2]);
		if (f[i] > 1000000000) break;
	}

	while (tc--) {
		int n;
		scanf("%d", &n);

		vector<int>ans;

		while (n!=0) {
			int p = lower_bound(f.begin(), f.end(), n) - f.begin();
			if (f[p] > n && p > 0)  p--;
			ans.push_back(f[p]);
			n -= f[p];
		}

		reverse(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
		printf("\n");
	}
}
