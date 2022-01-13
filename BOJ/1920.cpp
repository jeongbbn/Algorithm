#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
using namespace std;
#define INF 1e9+10
int arr[100005];
bool binarySearch(int st, int end, int target) {
	while (st <= end) {
		int mid = (st + end) / 2;
		if (arr[mid] == target) return 1;
		else if (arr[mid] < target) st=mid + 1;
		else end=mid - 1;
	}
	return 0;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		printf("%d\n", binarySearch(0, n - 1, a));
	}
	cout << *upper_bound(arr, arr + n, 10);
	
}
