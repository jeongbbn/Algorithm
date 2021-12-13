#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000000
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

int arr[1000000];
int n;

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	vector<int>v;
	v.push_back(arr[0]);
	int len = 1;
	for (int i = 1; i < n; i++)
	{
		if (v.back() < arr[i]) {
			v.push_back(arr[i]);
			len++;
		}
		else {
			auto p = lower_bound(v.begin(), v.end(), arr[i]);
			*p = arr[i];
		}
	}
	printf("%d", len);


}
