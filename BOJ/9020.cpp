#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<map>
#include <string>
#include<math.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int main() {

	long long n, k;

	while (scanf("%lld%lld", &n, &k) != EOF) {
		
		int ans=1;
		bool flag = false;
		for (int i = 2; i*i <= k; i++)
		{
			int tmp = 1, die;
			while (k%i == 0) {
				k /= i;
				tmp *= i;

				if (n < tmp) { 
					die = tmp / i;
					while (1) {

					}

					
					flag = true; 
					break; }
			}
			if(tmp!=1) ans *= tmp;
			if (flag) break;
		}
		if (ans == 0) ans = 1;
		printf("%d\n", ans);
	}

}
