#include <iostream>
#include <algorithm>
using namespace std;

struct pos {
	int x;
	int y;
};


int dp[50];
pos arr[50];
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &arr[i].x, &arr[i].y);
	}

	for (int i = 1; i <= n+1; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (arr[j].x + j <= i) {
				dp[i] = max(dp[j]+arr[j].y, dp[i]);
			}
		}
	}
	//test case 4�� ����, dp[7]dp[8] ��� 60�̰�, dp[9]dp[10]�� 80�̴�
	//�̷��� ������ �� �Ͱ�����, ������ ���õ�����, arr[j]�� �����ֱ� ������ ���x
	//dp[11]�� 90 �ǰ� �ִ��� �ȴ�.
	int maxx = dp[1];
	for (int i = 2; i <= n+1; i++)
	{
		maxx = maxx > dp[i] ? maxx : dp[i];
	}

	printf("%d", maxx);

}
