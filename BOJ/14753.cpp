#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 2000000
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int n, arr[10005];
vector<int>ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	
	ans.push_back(arr[0] * arr[1]);
	ans.push_back(arr[0] * arr[1] * arr[n - 1]);
	ans.push_back(arr[n - 1] * arr[n - 2]);
	ans.push_back(arr[n - 1] * arr[n - 2] * arr[n - 3]);
	
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());
	printf("%d", ans[0]);
}
