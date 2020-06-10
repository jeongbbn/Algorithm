#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int main() {
	int n, arr[80005];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	stack<int>s;

	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		while (!s.empty() && s.top() <= arr[i]) s.pop();

		s.push(arr[i]);
		int size = s.size();
		sum += size - 1; //하나가 들어올 때마다 더해주고 있기 때문에 괜찮다.
	}

	printf("%lld", sum);
}
