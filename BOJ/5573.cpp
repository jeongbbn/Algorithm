#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 100000

/*
	목표 : N번째 산책경로

	배열판이 계속해서 토글되기 때문에 
	어떤 위치에 홀수번째로 접근하면, 처음 배열에 주어진대로 움직이고
	짝수번째로 접근하게 되면, 토글된 방향으로 움직인다.

	이러한 특성을 이용해서
	N-1번째 산책했을 때, 배열판이 어떻게 되는지를 구해놓는다.
	홀/짝에 따라서 갈라지기 때문에, 
	갈림길에서 두 위치에 가는 경우의 수는 각각 N/2, N/2이다.
	(ex. 현재 arr[x][y] = 1이고 9번 움직이는 경우, 아래쪽으로 4번 오른쪽으로 5번 간다)

	이를 이용하여, dp[x][y] : N-1번 움직였을 때, 해당 x,y칸에 몇번 들렸는지를 구하고
	만약 dp[x][y]%2==1이라면, 해당 칸에 홀수번 갔다는 뜻이므로,
	다음 차례에서는 반대편으로 가야됨을 알 수 있다.

	이렇게 N번째의 배열판을 구하고, dfs로 직접 돌아준다음 답을 구한다.
*/


int w, h, n, dp[1005][1005];
bool arr[1005][1005];

void dfs(int x, int y) {
	if (x >= h || y >= w) {
		cout << x + 1 << " " << y + 1;
		return;
	}

	if (dp[x][y] % 2 == 1) {
		arr[x][y] = !arr[x][y];
	}

	if (arr[x][y]) dfs(x, y + 1);
	else dfs(x + 1, y);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> h >> w >> n;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> arr[i][j];

	dp[0][0] = n - 1;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int diff = dp[i][j];
			if (arr[i][j]) {
				dp[i][j + 1] += diff / 2 + (diff % 2);
				dp[i + 1][j] += diff / 2;
			}
			else {
				dp[i + 1][j] += diff / 2 + (diff % 2);
				dp[i][j + 1] += diff / 2;
			}
		}
	}

	dfs(0, 0);
}
