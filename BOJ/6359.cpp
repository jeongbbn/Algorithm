#include <iostream>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int n, cnt = 0;
		scanf("%d", &n);
		bool open[101];

		for (int i = 1; i <= n; i++)
			open[i] = 1;

		for (int i = 2; i <= n; i++)
		{
			for (int j = i; j <= n; j += i)
			{
				if (open[j]) open[j] = 0;
				else open[j] = 1;
			}
		}

		for (int i = 1; i <= n; i++)
			if (open[i]) cnt++;

		printf("%d\n", cnt);

	}
}
