#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

int t, arr[15], tmp[15], n;

void jjak() {
	for (int i = 0; i < n; i++)
		if (arr[i] % 2 != 0) arr[i]++;
}

int func(int cnt) {
	jjak();
	bool flag = 1;
	for (int i = 0; i < n - 1; i++)
		if (arr[i] != arr[i + 1]) flag = 0;
	if (flag) return cnt;

	for (int i = 0; i < n; i++)
	{
		arr[i] = arr[i] / 2;
	}

	for (int i = 0; i < n; i++)
	{
		if (i == n - 1) tmp[0] = arr[0] + arr[i];
		else tmp[i + 1] = arr[i] + arr[i + 1];
	}
	for (int i = 0; i < n; i++) arr[i] = tmp[i];
	return func(cnt + 1);
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
		printf("%d\n", func(0));
	}
}
