#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
using namespace std;
#define INF 1e9+10
typedef pair<int, int>p;

bool isPrime[10005];

void sieve() {
	for (int i = 2; i < 10005; i++)
		isPrime[i] = true;

	for (int i = 2; i*i < 10005; i++) {
		if (!isPrime[i]) continue;
		for (int j = i*i; j < 10005; j+=i)
			isPrime[j] = 0;
	}
}

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	sieve();

	int sum = 0, cnt = 0, minn;
	for (int i = a; i <= b; i++)
	{
		if (isPrime[i]) {
			sum += i;
			if (cnt == 0) {
				minn = i;
				cnt++;
			}
		}
	}
	if (cnt == 0) {
		printf("-1"); return 0;
	}
	printf("%d\n", sum);
	printf("%d\n", minn);

}
