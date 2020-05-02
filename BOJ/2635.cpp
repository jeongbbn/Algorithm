#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int n, maxx;
vector<int>ans (1, 0);
int main() {
	scanf("%d", &n);

	for (int i = n/2; i <= n; i++)
	{
		int x = n;
		int y = i;
		int cnt = 0;
		vector<int>arr;
		while (x >= 0) {
			arr.push_back(x);
			int tmp = y;
			y = x - y;
			x = tmp;
			cnt++;
		}

		if (cnt > maxx) {
			maxx = cnt;
			ans.clear();
			for (int i = 0; i < arr.size(); i++)
				ans.push_back(arr[i]);
		}
	}

	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[i]);
	}
}
