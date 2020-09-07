#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int n, m;
vector<int>arr;
int main() {
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n ; i++)
		arr.push_back(i);
	
	int p = 0;
	printf("<");
	while (arr.size()!=1) {
		p = (p + m-1)%n;
		printf("%d, ", arr[p]);
		arr.erase(arr.begin() + p);
		n--;
	}
	printf("%d>", arr[0]);
}
