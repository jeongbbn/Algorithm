#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

int h, m;
int main() {
	scanf("%d %d", &h, &m);
	if (m >= 45) m -= 45;
	else {
		h--; m += 60;
		m -= 45;
		if (h < 0) h = 23;
	}
	printf("%d %d", h, m);
}
