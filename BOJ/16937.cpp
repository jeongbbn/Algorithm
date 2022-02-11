#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

int h, w, n, ans;
pi arr[105];

int main() {
	scanf("%d%d", &h, &w);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &arr[i].first, &arr[i].second);
	}

	for (int i = 0; i < n - 1; i++)
	{
		int x = arr[i].first;
		int y = arr[i].second;

		int width1 = w - y;
		int height1 = h - x;

		int width2 = w - x;
		int height2 = h - y;

		int sum = x * y;
		for (int j = i + 1; j < n; j++)
		{
			int nx = arr[j].first;
			int ny = arr[j].second;

			if (width1 > 0 && height1 > 0) {
				if ((nx <= h && ny <= width1) ||
					(nx <= height1 && ny <= w)) {
					ans = max(ans, sum + (nx*ny));
				}

				if ((ny <= h && nx <= width1) ||
					(ny <= height1 && nx <= w)) {
					ans = max(ans, sum + (nx*ny));
				}
			}
			
			if (height2 > 0 && width2 > 0) {
				if ((nx <= h && ny <= width2) ||
					(nx <= height2 && ny <= w)) {
					ans = max(ans, sum + (nx*ny));
				}
				if ((ny <= h && nx <= width2) ||
					(ny <= height2 && nx <= w)) {
					ans = max(ans, sum + (nx*ny));
				}
			}
		}
	}
	printf("%d", ans);
}
