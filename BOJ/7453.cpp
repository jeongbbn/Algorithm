#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
using namespace std;
#define INF 1e9+10
long long A[4005], B[4005], C[4005], D[4005];
vector<long long>CD;
int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lld%lld%lld%lld", &A[i], &B[i], &C[i], &D[i]);
	}
		
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			CD.push_back(C[i] + D[j]);
		}
	}

	sort(CD.begin(), CD.end());
	long long ans=0;


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			long long target = (A[i]+B[j]) * -1;
			if (!binary_search(CD.begin(), CD.end(), target)) continue;

			long long left = lower_bound(CD.begin(), CD.end(), target) - CD.begin();
			long long right = upper_bound(CD.begin(), CD.end(), target) - CD.begin();

			ans += (right - left);
		}
	}

	printf("%lld", ans);

}
