#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000000
typedef pair<string, bool>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int t;

bool find(int N) {
	for (int i = 2; i <= 64; i++)
	{
		int n = N;
		vector<int>v;
		while (n > 0) {
			v.push_back(n%i);
			n /= i;
		}

		int len = v.size();
		bool flag = 1;
		for (int j = 0; j <= len/2; j++)
		{
			if (v[j] != v[len - j - 1]) {
				flag = 0; break;
			}
		}
		if (flag) return 1;
	}

	return 0;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", find(n));
	}
}
