#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		char str[81];
		int k = 0, sum = 0 ,arr[81] = { 0, };
		scanf("%s", str);

		if (str[k] == 'O') arr[0] = 1;

		for (k = 1; str[k]; k++)
		{
			if (str[k] == 'O') {
				arr[k] = arr[k - 1] + 1;
			}
			else arr[k] = 0;
		}

		for (int i = 0; str[i]; i++) {
			sum += arr[i];
		}

		printf("%d\n", sum);

	}
}
