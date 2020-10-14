/*
Codeforces Round #555 (Div. 3)
C2. Increasing Subsequence (hard version)
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 1e9
typedef long long ll;
int arr[200005];

string ans;
int p = -1;
string func(int x, int y, bool gotoLeft, int flag, string tmp) {
	if (gotoLeft) {
		for (int i = x; i >= y; i--)
		{
			if (flag < arr[i]) {
				flag = arr[i];
				tmp += 'R';
			}
			else break;
		}
	}
	else {
		for (int i = x; i <= y; i++)
		{
			if (flag < arr[i]) {
				flag = arr[i];
				tmp += 'L';
			}
			else break;
		}
	}
	return tmp;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	int st = 0, en = n - 1;
	bool flag = 0;
	while (st <= en) {
		if (flag) break;

		if (arr[st] < arr[en]) {
			if (p < arr[st]) {
				ans += 'L';
				p = arr[st];
				st++;
			}
			else if (p < arr[en]) {
				flag = 1;
				ans += 'R';
				p = arr[en];
				en--;
				ans = func(en, st, 1, p, ans);
			}
		}

		else if (arr[st] > arr[en]) {
			if (p < arr[en]) {
				ans += 'R';
				p = arr[en];
				en--;
			}
			else if (p < arr[st]) {
				flag = 1;
				ans += 'L';
				p = arr[st];
				st++;
				ans = func(st, en, 0, p, ans);
			}
		}
		//arr[st] == arr[en]
		else {
			if (arr[st] > p) {
				flag = 1;
				string tmp1 = func(en, st, 1, p, ans);
				string tmp2 = func(st, en, 0, p, ans);

				if (tmp1.size() < tmp2.size()) ans = tmp2;
				else ans = tmp1;
			}
		}
	}
	printf("%d\n", ans.size());
	cout << ans;
}
