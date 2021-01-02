#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<map>
#include <string>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	int n,m;
	scanf("%d%d", &n,&m);

	int a=gcd(n, m);
	int b = n * m / a;
	printf("%d\n%d", a, b);
}
