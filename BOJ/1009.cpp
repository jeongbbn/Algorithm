#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int n;
int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		bool check[10] = { 0, };
		int a, b;
		scanf("%d %d", &a, &b);

		int cnt = 0;
		int tmp = a % 10;
		bool flag = 0;
		for (int i = 1; i < b; i++)
		{
			if (check[tmp]) { flag = 1;  break; }
			check[tmp] = 1;
			tmp = (a * tmp) % 10;
			cnt++;
		}

		if (flag) {
			int end = b % cnt;
			int k = 1;

			if (b%cnt == 0) end = cnt;
			for (int i = 0; i < end; i++)
			{
				k *= a;
				k = (k % 10);
			}

			if (k == 0) k = 10;
			printf("%d\n", k);
		}
		else {
			if (tmp == 0) tmp = 10;
			printf("%d\n", tmp);
		}
	
	}


}
