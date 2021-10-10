#include <iostream>
#include <vector>
using namespace std;

int n, m;
int i, j, k;
vector<int>a1,a2,a3;

int main() {
	scanf("%d%d", &n, &m);
	a1.resize(n);
	a2.resize(m);
	a3.resize(n + m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a1[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &a2[i]);
	
	while (i < n && j < m) {
		if (a1[i] < a2[j]) 
			a3[k++] = a1[i++];
		else 
			a3[k++] = a2[j++];
	}
	while (i < n)
		a3[k++] = a1[i++];
	while (j < m)
		a3[k++] = a2[j++];

	for (int i = 0; i < n + m; i++)
		printf("%d ", a3[i]);
	
	return 0;
}
