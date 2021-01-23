#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<set>
#include<map>
#include <string>
using namespace std;
#define INF 1e7
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n,arr[10005],cnt;
long long sum;
bool zero = false;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] <= 0) cnt++;
	}

	sort(arr + 1, arr + n + 1);

	int i;
	for (i = 1; i + 1 <= cnt; i += 2)
	{
		int tmp = arr[i] * arr[i + 1];
		sum += tmp;
	}
	if (i <= cnt) { sum += arr[i]; }

	int j;
	for (j = n; j - 1 > cnt; j -= 2)
	{
		if (arr[j] == 1 || arr[j - 1] == 1) { sum += (arr[j] + arr[j - 1]); continue; }
		else {
			int tmp = arr[j] * arr[j - 1];
			sum += tmp;
		}
	}
	if (j > cnt) { sum += arr[j]; }

	printf("%lld", sum);
}
