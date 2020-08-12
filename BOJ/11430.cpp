#include<iostream>
#include<math.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);

		int sum = (15 * a + 20 * b + 25 * c);
		double ans = 9000 - sum;
		ans = ans / 40;
		ans = ceil(ans);

		int rans = (int)ans;
		if (ans > 100) printf("impossible\n");
		else printf("%d\n", rans);
	}
}
