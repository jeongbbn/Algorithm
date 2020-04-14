#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<map>
#include <string>
using namespace std;
#define INF 800*1000
typedef pair<int, int>pii;
int main() {
	int n, k, arr[10005];
	scanf("%d%d", &k,&n);
	for (int i = 0; i < k; i++)
		scanf("%d", &arr[i]);
		
	sort(arr, arr + k);

	long long st = 1, en = 1000000000;
	int a = 0;
	while (st + 1 < en) {
		long long mid = (st + en) / 2;
		

		for (int i = 0; i < k-1; i++)
		{
			if (arr[i] >= arr[a] + mid) {
				st = mid; 
				a = i;
				break;
			}
		}
		if (st != mid) en = mid;

	}
	printf("%lld", st);
}
