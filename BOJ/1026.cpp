#include <iostream>
#include <algorithm>
using namespace std;

bool rev(int a, int b) {
	if (a > b) return 1;
	else return 0;
}

int main() {
	int n, A[51],B[51], sum=0;
	scanf("%d", &n);

	for (int j = 0; j < n; j++)
		scanf("%d", &A[j]);
	for (int j = 0; j < n; j++)
		scanf("%d", &B[j]);

	sort(A, A + n, rev);
	sort(B, B + n);

	for (int i = 0; i < n; i++)
		sum += A[i] * B[i];

	printf("%d", sum);
}
