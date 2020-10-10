#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<set>
#include<math.h>
#include<map>
#include <string>
using namespace std;
#define INF 1e7
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

vector<int>s;

int arr[500005];
int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr+1, arr + n+1);
	
	long long sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] == i) continue;
		
		sum += (i - arr[i] < 0 ? (i - arr[i])*-1 : i - arr[i]);
	}
	printf("%lld", sum);
}
