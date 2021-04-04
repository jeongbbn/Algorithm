#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int main() {
	vector<int>v;
	scanf("%d", &n);
	v.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
		printf("%d\n", v[i]);

	return 0;
}
