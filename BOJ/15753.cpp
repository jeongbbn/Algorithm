#include<bits/stdc++.h>
using namespace std;
#define INF 98765421
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n, arr[105], chk[105];
bool ans = 1;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

	int flag = -1;
	for (int i = n-1; i >= 0; i--)
	{
		if (arr[i] == 0) chk[i] = 1;
		else chk[i] = 0;

		if (flag != -1){
			if (arr[i] == -1) {
				if (flag == 0) chk[i] = 1;
			}
			else {
				if (flag != arr[i]) {
					ans = 0; break;
				}
			}
			flag--;
		}
		else {
			if (arr[i] == -1) { chk[i] = -1; continue; }
			else {
				if (i - arr[i] < 0) { ans = 0; break; }
				flag = arr[i] - 1;
			}
		}
	}

	if (ans) {
		int minn = 1, maxx = 1;
		for (int i = 1; i < n; i++)
		{
			if (chk[i] == -1) maxx++;
			if (chk[i] == 1) { maxx++; minn++; }
		}
		printf("%d %d", minn, maxx);
	}
	else printf("-1");
}
