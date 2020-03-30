#include <bits/stdc++.h>
using namespace std;
int main() {
	int a[10], b[10];
	for (int i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < 10; i++)
		scanf("%d", &b[i]);

	char winner = 'D';
	int sumA = 0, sumB = 0;
	for (int i = 0; i < 10; i++)
	{
		if (a[i] < b[i]) { sumB += 3; winner = 'B'; }
		else if (a[i] > b[i]) { sumA += 3; winner = 'A'; }
		else { sumA += 1; sumB += 1; }
	}

	if (sumA > sumB) winner = 'A';
	else if (sumA < sumB) winner = 'B';

	printf("%d %d\n", sumA, sumB);
	printf("%c", winner);
}
