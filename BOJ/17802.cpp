#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int n,arr[10];
int main() {
	while (1) {
		int n = 0;
		scanf("%d", &n);
		if (n == 0) return 0;

		int k = 0;
		while (n) {
			arr[k++] = n % 10;
			n = n / 10;
		}

		bool flag = 1;
		for (int i = 0; i < k/2; i++)
		{
			if (arr[i] != arr[(k-1)-i]) { flag = 0; break; }
		}
		if (flag) printf("yes\n");
		else printf("no\n");
	}
}
