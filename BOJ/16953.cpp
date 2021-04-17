#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;


int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	
	int cnt = 0;
	while (b != 0) {

		if (b % 2 == 0) b /= 2;
		else if (b % 10 == 1) b /= 10;
		else break;
		cnt++;

		if (b == a) {
			printf("%d", cnt+1);
			return 0;
		}
	}
	printf("-1");
}
