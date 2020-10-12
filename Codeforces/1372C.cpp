#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 1e9
typedef long long ll;

int main() {
	int t;
	scanf("%d", &t);
	
	while (t--) {
		int n;
		scanf("%d", &n);
		vector<int>arr, chk;
		arr.resize(n); chk.resize(n);
		for (int i = 0; i < n; i++)
		{
			int a;
			scanf("%d", &a);
			arr[i] = a - 1;
			if (arr[i] == i) chk[i] = 1;
		}

		int st = 0, en = n - 1;
		for (st = 0; st < n; st++) if (chk[st] != 1) break;
		for (en = n - 1; en >= 0; en--) if (chk[en] != 1) break;

		if (st >= en) {
			printf("0\n"); continue;
		}
		bool flag = 0;
		for (int i = st; i <= en; i++)
		{
			if (chk[i] == 1) flag = 1;
		}
		if (flag) printf("2\n");
		else printf("1\n");
	}
}
