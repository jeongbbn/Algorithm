#include <iostream>
using namespace std;

int sum, cnt, a ,b, c,tmp;
int main() {
	int n;
	scanf("%d", &n);
	sum = n;
	while (1) {
		a = sum % 10;
		c = sum / 10;
		tmp = a + c;
		b = tmp % 10;

		sum = a * 10 + b;
		cnt++;
		if (sum == n) break;
		
	}
	printf("%d", cnt);
}
