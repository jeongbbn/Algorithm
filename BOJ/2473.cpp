#include <bits/stdc++.h>
using namespace std;
#define INF 4000000000LL

/*
Ʋ�ȴ� ����
1. INF long long, abs�� long long ó���� ���ϳ���
2.  if (sum >= 0) en--; ���� sum ��� arr[st]+arr[en]�ϰ��� ����
������ arr[i]�� ������ x�� �ΰ�, �� �Ѹ� üũ���ָ� �ɰŶ� �����ߴµ�
�� arr[i]�� ���� �ȴٰ� ����������?
arr[i]�� �Ÿ���꿡 �ʿ��ѵ�..

*/

int main() {
	int n;
	long long arr[5005];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);

	sort(arr, arr + n);
	long long dist = INF, ans[3];

	for (int i = 0; i < n; i++)
	{		
		int st = 0, en = n - 1;

		while (1) {
			if (i == st) st++;
			if (i == en) en--;

			if (st == en) break;

			long long sum = arr[st] + arr[en] + arr[i];
			long long abssum = sum > 0 ? sum : -sum;

			if (dist > abssum) {
				ans[0] = arr[st];
				ans[1] = arr[i];
				ans[2] = arr[en];

				dist = abssum;
			}

			if (sum >= 0) en--;
			else st++;
		}
	}

	sort(ans, ans + 3);
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", ans[i]);
	}
}
