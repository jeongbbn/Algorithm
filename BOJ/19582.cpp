#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

int tc, n, maxx, sum, second;
pi arr[100005];
bool flag, ans = 1;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &arr[i].first, &arr[i].second);
	}

	priority_queue<int, vector<int>> pq;
	pq.push(arr[0].second);
	sum = arr[0].second;

	for (int i = 1; i < n; i++)
	{
		int x = arr[i].first;
		int y = arr[i].second;

		if (sum > x) {
			if (flag) {
				ans = 0;
				break;
			}
			else {
				flag = 1;
				if (pq.top() >= y && sum - pq.top() <= x) {
					sum -= pq.top();
					pq.pop();
				}
				else continue;
			}
		}
		pq.push(y);
		sum += y;
	}

	if (ans) printf("Kkeo-eok");
	else printf("Zzz");
}
