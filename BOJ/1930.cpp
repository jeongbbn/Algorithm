#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;
typedef pair<int, pair<int, int>> pii;

int dx[] = { 0,2,1,1 };
int dy[] = { 0,3,3,2 };

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int s1[4][4], s2[4];
		for (int i = 0; i < 4; i++) scanf("%d", &s1[0][i]);
		for (int i = 0; i < 4; i++) scanf("%d", &s2[i]);

		for (int i = 1; i < 4; i++) { s1[i][0] = s1[0][i]; s1[i][1] = s1[0][0];}
		s1[1][2] = s1[0][3]; s1[1][3] = s1[0][2];
		s1[2][2] = s1[0][1]; s1[2][3] = s1[0][3];
		s1[3][2] = s1[0][2]; s1[3][3] = s1[0][1];

		bool ans = 0;
		for (int i = 0; i < 4; i++)
		{
			int loop = 3;
			while (loop--) {
				bool flag = 1;
				for (int j = 0; j < 4; j++)
				{
					if (s1[i][j] != s2[j]) {
						flag = 0;  break;
					}
				}
				if (flag) { ans = 1; break; }
				int tmp1 = s1[i][1];
				s1[i][1] = s1[i][2]; s1[i][2] = s1[i][3]; s1[i][3] = tmp1;
			}
			if(ans) break;
		}
		printf("%d\n", ans);
	}
}
