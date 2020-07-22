#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define digit 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n;
pi arr[100005];
int trace[100005];
bool ans[100005];
vector<int>vt;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &arr[i].first, &arr[i].second);
	}
	sort(arr, arr + n);

	vt.push_back(arr[0].second);
	trace[0] = 1;

	for (int i = 1; i < n; i++)
	{
		if (vt.back() < arr[i].second) {
			vt.push_back(arr[i].second);
			trace[i] = vt.size();
		}
		else {
			auto p = lower_bound(vt.begin(), vt.end(), arr[i].second);
			*p = arr[i].second;
			trace[i] = p - vt.begin() + 1;
		}
	}

	int flag = *max_element(trace, trace + n);
	printf("%d\n", n - flag);

	for (int i = n-1; i >= 0; i--)
	{
		if (trace[i] == flag) {
			flag--;
			ans[i] = 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (ans[i] == 1) continue;
		printf("%d\n", arr[i].first);
	}
}
