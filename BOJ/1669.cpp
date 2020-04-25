#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<set>
#include<map>
#include <string>
#include<cstring>
using namespace std;
#define INF 1e9

int main() {
	long long x, y;
	scanf("%lld%lld", &x, &y);
	
	long long diff = y - x;
	long long n = 1;
	while (1) { 
		if (n*(n + 1) >= diff) break;
		n++; 
	}
	n -= 1;

	diff = diff - n * (n + 1);
	long long cnt = n * 2;

	if (diff % (n + 1) != 0) cnt += 1;
	cnt += (diff / (n + 1));

	printf("%lld", cnt);
}
