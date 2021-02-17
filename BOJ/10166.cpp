#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, bool>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int x, y, ans;
int blue[2005];
bool need[2005];

int main() {
	cin >> x >> y;

	//우선 모든 점을 넣어준다
	for (int i = 1; i <= y; i++) blue[i] = i;

	//현재 수(now)가 만들어낼 수 있는 모든 배수들에 대해 now의 점을 뺌
	//now의 배수라는 건, 해당 위치에서 now의 점들이 겹친다는 소리임
	for (int now = 1; now <= y; now++)
	{
		for (int i = 2 * now; i <= y; i += now)
		{
			blue[i] -= blue[now];
			//만약 now의 배수인 i가 x~y 범위에 없다면, 나중에 이 점들은 살려줘야한다.
			if (x <= i && i <= y) need[now] = 1;
		}
	}

	//우선 x~y의 파란점을 구해주고
	for (int now = x; now <= y; now++) ans += blue[now];

	//아까 살려주기로 한 점들을 더해준다.
	for (int i = 1; i < x; i++) {
		if (need[i]) ans += blue[i];
	}

	cout << ans;
}
