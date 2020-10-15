#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

string str;
int n, sum;
int key[15];
int table[15][15];
bool chk;
void dfs(int k) {
	if (chk == 1) return;

	if (k == n) {
		for (int i = 0; i < n; i++)
			printf("%d ", key[i]);
		chk = 1;
		return;
	}

	//양
	if (table[k][k] == 1) {
		for (int i = 1; i <= 10; i++)
		{
			int tmp = sum;
			bool flag = 1;
			for (int j = 0; j <= k; j++)
			{
				if (table[k][j] == 1) {
					if (tmp + i <= 0) {
						flag = 0;  break;
					}
					else tmp -= key[j];
				}

				if (table[k][j] == -1) {
					if (tmp + i >= 0) {
						flag = 0;  break;
					}
					else tmp -= key[j];
				}

				if (table[k][j] == -2) {
					if (tmp + i != 0) {
						flag = 0;  break;
					}
					else tmp -= key[j];
				}
			}
			if (flag) {
				key[k] = i;
				sum += key[k];
				dfs(k + 1);
				sum -= key[k];
			}
		}
	}

	//음
	else {
		for (int i = -10; i <= 0; i++)
		{
			int tmp = sum;
			bool flag = 1;
			for (int j = 0; j <= k; j++)
			{
				if (table[k][j] == 1) {
					if (tmp + i <= 0) {
						flag = 0;  break;
					}
					else tmp -= key[j];
				}

				if (table[k][j] == -1) {
					if (tmp + i >= 0) {
						flag = 0;  break;
					}
					else tmp -= key[j];
				}

				if (table[k][j] == -2) {
					if (tmp + i != 0) {
						flag = 0;  break;
					}
					else tmp -= key[j];
				}
			}
			if (flag) {
				key[k] = i;
				sum += key[k];
				dfs(k + 1);
				sum -= key[k];
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	cin >> str;

	int p = 0;
	for (int i = n , k = 0; i >= 0; i--, k++) // i : 4 3 2 1 뭉텅이로 끊어주는 역할
		// k : 합의 시작점 인덱스
	{
		for (int j = p, w = k; j < p + i; j++, w++) //j : str 순회용, j-p+k : 정답 인덱스
		{
			if (str[j] == '+') table[w][k] = 1;
			else if (str[j] == '-') table[w][k] = -1;
			else table[w][k] = -2;
		}
		p += i;
	}
	dfs(0);
}
