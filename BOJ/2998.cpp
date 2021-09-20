#include <iostream>
using namespace std;

bool sieve[1005];

int main() {
	int n, k, cnt=0;#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pi;

string str, ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> str;
	reverse(str.begin(), str.end());

	int n = str.size();
	if (n % 3 != 0) {
		for (int i = 0; i < 3 - (n % 3); i++) str += "0";
	}

	int N = str.size();
	for (int i = 0; i < (N / 3); i++) {
		string tmp = str.substr(i*3, 3);
		int sum = 0;
		for (int j = 0, t = 1; j < 3; j++, t*=2)
			sum += (tmp[j] - '0') * t;
		ans += to_string(sum);
	}

	reverse(ans.begin(), ans.end());
	cout << ans;
}
	scanf("%d%d", &n, &k);

	for (int i = 2; i <= n; i++) sieve[i] = 1;

	for (int i = 2; i <= n; i++)
	{
		if (!sieve[i]) continue;
		for (int j = i*i; j <= n; j+=i)
		{
			sieve[j] = 0;
			cnt++;
			if (cnt == k) {
				printf("%d", j);
				return 0;
			}
			
		}
	}
}
