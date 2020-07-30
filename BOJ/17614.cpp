#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<set>
#include<map>
#include <string>
#include <cstring>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int main() {
	int n;
	scanf("%d", &n);

	int cnt = 0;
	while (n != 0) {
		int tmp = n;

		while (tmp != 0) {
			int k = tmp % 10;
			if (k == 3 || k == 6 || k == 9) cnt++;
			tmp = tmp / 10;
		}
		n--;
	}
	printf("%d", cnt);
}
