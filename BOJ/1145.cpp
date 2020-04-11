#include <iostream>
using namespace std;
int arr[5];
int main() {
	for (int i = 0; i < 5; i++) scanf("%d", &arr[i]);

	for (int i = 1;; i++)
	{
		int cnt = 0;
		for (int j = 0; j < 5; j++)
		{
			if (i%arr[j] == 0) {
				cnt++;
			}
			if (cnt > 2) {
				printf("%d", i);
				return 0;
			}
		}
	}
}
