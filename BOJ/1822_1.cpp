#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
using namespace std;
#define INF 1e9+10
int A[500005], B[500005];
vector<int>ans;
int main() {
	int a, b;
	scanf("%d%d", &a, &b);

	for (int i = 0; i < a; i++)
		scanf("%d", &A[i]);

	for (int i = 0; i < b; i++)
		scanf("%d", &B[i]);

	sort(A, A + a);
	sort(B, B + b);

	for (int i = 0; i < a; i++)
	{
		int target = A[i];
		if (!binary_search(B, B + b, target)) {
			ans.push_back(target);
		}
	}


	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[i]);
	}
}
