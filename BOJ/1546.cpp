#include <iostream>
using namespace std;
int n;
int arr[1001], maxx;
double sum;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		maxx = maxx > arr[i] ? maxx : arr[i];
	}

	for (int i = 0; i < n; i++)
		sum += (double)arr[i] / maxx * 100;

	printf("%f", sum / n);
}
