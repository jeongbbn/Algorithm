#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<set>
#include<map>
#include <string>
using namespace std;
#define INF 1e7
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;


bool cmp(pi a, pi b) {
	if (a.second != b.second) return a.second > b.second;
	else return a.first < b.first;
}

int main() {

	pi arr[105];
	int n, k;
	scanf("%d%d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d%d", &arr[i].first, &arr[i].second);
	}
	sort(arr, arr + n, cmp);

	int maxx = 0;
	for (int i = 0; i < n; i++)
	{
		int wsum = arr[i].first;
		int vsum = arr[i].second;

		if (wsum > k) continue;
		else if (wsum == k) {
			maxx = vsum;
			continue;
		}

		for (int j = i + 1; j < n; j++)
		{
			if (wsum + arr[j].first > k) continue;
			wsum += arr[j].first;
			vsum += arr[j].second;
		}
		maxx = max(maxx, vsum);
	}
	printf("%d\n", maxx);

}
