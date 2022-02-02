#include <iostream>
using namespace std;

//O(log b)
long long pow(int a, int b, int c) {
	if (b == 0) return 1;
	long long ans = pow(a, b / 2, c);
	ans = ans * ans %c;
	if (b % 2 == 0) return ans;
	else return ans*a%c;
	// ans*a%c == (ans*a)%c == (ans%c * a%c)%c
	// ans는 이미 위에서 나머지 연산을 해주었기 때문에
	// 여기서 %c를 만난다해도, 값이 달라지지않음
	//https://www.acmicpc.net/problem/10430
}

//O(b) : 함수를 두 번 호출해서
//long long POW(int a, int b, int c) {
//	if (b == 0) return 1;
//	if (b % 2 == 0) return POW(a, b / 2, c) * POW(a, b / 2, c) % c;
//	return a*POW(a, b / 2, c) * POW(a, b / 2, c) % c;
//}

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%lld", pow(a, b, c));
}
