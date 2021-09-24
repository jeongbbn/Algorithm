#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int n, T, k;
int arr[5][1005];

int main() {
	scanf("%d ", &T);

	while (T--) {
		scanf("%d%d", &k, &n);

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &arr[i][j]);
			}
		}

		vector<int>v;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				v.push_back(arr[0][i] + arr[1][j]);
			}
		}
		sort(v.begin(), v.end());

		int ans = INF;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int sum = arr[2][i] + arr[3][j];
				int x = k - sum;
				if (binary_search(v.begin(), v.end(), x)) ans = k;
				else {
					int p = lower_bound(v.begin(), v.end(), x) - v.begin();
					
					if (p != 0) {
						if(abs(ans - k) > abs(k - (v[p - 1] + sum))) ans = v[p - 1] + sum;
						else if(abs(ans - k) == abs(k - (v[p - 1] + sum))) ans = min(ans, v[p - 1] + sum);
					}
					if (p != v.size()) {
						if(abs(ans - k) > abs(k - (v[p] + sum))) ans = v[p] + sum;
						else if (abs(ans - k) == abs(k - (v[p] + sum))) ans = min(ans, v[p] + sum);
					}
				}
			}
		}

		printf("%d\n", ans);
	}
}
