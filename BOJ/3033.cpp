#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 100003
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

string str;
int n;
long long p[200005];

int main() {
	scanf("%d", &n);
	cin >> str;

	p[0] = 1;
	for (int i = 1; i < 200001; i++)
		p[i] = (p[i - 1] * 2) % mod;

	int st = 0, en = n ;
	while (st + 1 < en) {
		int mid = (st + en) / 2;

		long long H = 0, a = 2;
		vector<int>hash_[mod];

		for (int i = 0; i < mid; i++)
		{
			H = (H + str[i] * p[mid - i - 1]) % mod;
		}
		hash_[H].push_back(0);

		bool go = 0;
		for (int i = 1; i <= n - mid; i++)
		{
			bool same = 0;
			H = (H - p[mid - 1] * str[i - 1]) % mod;
			if (H < 0) H += mod;
			H = (H*a) % mod;
			H = (H + str[i - 1 + mid]) % mod;
			if (!hash_[H].empty()) {
				for (int k = 0; k < hash_[H].size(); k++)
				{
					bool same = 1;
					int x = hash_[H][k];
					for (int j = 0; j < mid; j++)
					{
						if (str[x + j] != str[i + j]) {
							same = 0; break;
						}
					}
					if (same) {
						go = 1;
						break;
					}
				}
			}
			if (same) break;
			else hash_[H].push_back(i);
		}
		if (go) st = mid;
		else en = mid;
	}
	printf("%d", st);
}
