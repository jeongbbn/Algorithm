#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

int GCD(int a, int b) {
	if (b == 0) return a;
	return GCD(b, a%b);
}

int n, m;
int main() {
	scanf("%d:%d", &n, &m);
	int a = GCD(n, m);
	printf("%d:%d", n/a, m/a);
}
