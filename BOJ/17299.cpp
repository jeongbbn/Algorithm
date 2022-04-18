#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;

int n, arr[1000005];
int chk[1000005], ans[1000005];
stack<pi>s;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		chk[arr[i]]++;
	}

	s.push({ arr[0],0 });
	for (int i = 1; i < n; i++)
	{
		while (!s.empty() && chk[arr[i]] > chk[s.top().first]) {
			ans[s.top().second] = arr[i];
			s.pop();
		}
		s.push({ arr[i], i });
	}

	while (!s.empty()) {
		ans[s.top().second] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", ans[i]);
	}
}
