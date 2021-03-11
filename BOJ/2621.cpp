#include <bits/stdc++.h>
using namespace std;
#define R 0
#define B 1
#define Y 2
#define G 3

int color[5], number[10];
int ans[15];
int main() {

	for (int i = 0; i < 5; i++) {
		int b;
		char a;
		scanf(" %c", &a);
		if(a=='R') color[0]++;
		if(a=='B') color[1]++;
		if(a=='Y') color[2]++;
		if(a=='G') color[3]++;

		scanf("%d", &b);
		number[b]++;
	}

	//����
	bool sameColor = 0;
	for (int i = 0; i < 4; i++)
	{
		if (color[i] == 5) sameColor = 1;
	}

	//5
	bool sequence = 0;
	int cnt = 0;
	for (int i = 1; i <= 9; i++)
	{
		if (number[i] == 1) cnt++;
		else cnt = 0;
		if (cnt == 5) { sequence = 1; ans[5] = i + 500; break; }
	}

	//1, 4
	if (sameColor) { 
		int i;
		for (i = 9; i >= 0; i--)
			if (number[i] == 1) break;

		ans[4] = i + 600;
		if(sequence) ans[1] = i + 900;
	}

	//2
	int three = 0, two = 0;
	for (int i = 1; i <= 9; i++)
	{
		if (number[i] == 4) { ans[2] = 800 + i; break; }
		if (number[i] == 3) { 
			ans[6] = 400 + i; three = i;
			if (two > 0) ans[3] = three * 10 + 700 + two;
		}
		if (two > 0 && number[i] == 2) {
			if (two < i) ans[7] = i * 10 + two + 300;
			else ans[7] = two * 10 + i + 300;
		}
		if (number[i] == 2) { ans[8] = 200 + i; two = i;
			if(three > 0) ans[3] = three * 10 + 700 + two;
		}
	}

	bool finall = 1;
	for (int i = 1; i < 10; i++)
	{
		if (ans[i] != 0) finall = 0;
	}

	if (finall) {
		int i;
		for (i = 9; i >= 1; i--)
			if (number[i] > 0) break;

		ans[9] = i + 100;
	}

	printf("%d", *max_element(ans, ans + 10));
}
