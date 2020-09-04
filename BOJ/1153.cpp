#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int n, p[5];
bool prime[1000005];
void sieve() {
	fill(prime, prime + 1000002, 1);

	for (int i = 2; i*i <= 1000000; i++)
	{
		if (!prime[i]) continue;
		for (int j = i*i; j <= 1000000; j+=i)
		{
			prime[j] = 0;
		}
	}
}

vector<int>arr;
int p1, p2, p3, p4;
int main() {
	scanf("%d", &n);
	sieve();

	for (int i = 2; i <= 1000000; i++)
		if (prime[i]) arr.push_back(i);

	int idx = 4;
	while (idx > 0) {
		int sum = 0;

		for (int i = 1; i <= 4; i++)
			sum += arr[p[i]];

		if (sum == n) {
			printf("%d %d %d %d", arr[p[1]], arr[p[2]], arr[p[3]], arr[p[4]]);
			return 0;
		}

		if (sum < n) {
			p[idx]++;
			if (p[idx] == arr.size()) { p[idx]--; idx--; }
		}
		else if(sum > n) {
			p[idx]--;
			if (p[idx] == -1) break;
			idx--;
		}
	}
	printf("-1");
}
