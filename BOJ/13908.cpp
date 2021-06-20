#include <iostream>
using namespace std;
int arr[7],fact[10], C[10][10];
int main() {
	int n,k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++)
		scanf("%d", &arr[i]);

	fact[0] = 1;
	fact[1] = 1;
	for (int i = 2; i <= n; i++)
		fact[i] = fact[i - 1] * i;

	C[1][0] = 1;
	C[1][1] = 1;
	for (int i = 2; i <= 10; i++)
	{
		C[i][0] = 1;
		for (int j = 1; j <= 10; j++)
		{
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}
	}

	int tmp = C[10 - k][1] * (n - k);
	if (n - k == 0) tmp = 1;

	int sum = C[n][k] * tmp * fact[k];
	for (int i = 1; i <= n-k; i++)
	{
		int tmp = C[10 - k][1] * (n - k - i);
		if ((n - k - i) == 0) tmp = 1;
		sum +=  C[k][i] * tmp * fact[k+i] / (fact[k+i]*fact[k-i]);
	}

	printf("%d", sum);

}
