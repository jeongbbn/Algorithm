#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
using namespace std;
#define INF 1e9+10
int A[500005], B[500005];
vector<int>ans;

bool binarySearch(int st, int end, int target) {
	while (st <= end) {
		int mid = (st + end) / 2;
		if (B[mid] == target) return 1;
		else if (B[mid] > target) end = mid-1;
		else st = mid + 1;
	}
	return 0;
}





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
		if (!binarySearch(0, b-1, target)) {
			ans.push_back(target);
		}
	}


	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[i]);
	}
}
