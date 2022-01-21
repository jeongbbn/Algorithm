#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pi;
#define INF 1e9 + 1
ll x, y, z, ans = INF;

/*
    al : parametric search
    ds : 배열
    ec : 1) 이미 승률이 100퍼인 경우, 더이상 오르지 않는다. 
         2) 99퍼인 경우에도 더이상 오르지 않는다. -> 99/100이어도, 100/101, ... 이렇게 될 테니까!
        
    c : 1) long long을 써줘야 한다. -> y = 1e9인 경우 19번 째 줄에서 overflow
        2) en = 1e9이 자명하다. -> 무조건 100퍼가 나온다.
*/

int main() {
	cin >> x >> y;
	z = (y * 100) / x;

	ll st = 0, en = 1e9;
	while (st <= en) {
		ll mid = (st + en) / 2;
		ll newZ = ((y + mid) * 100) / (x + mid);

		if (newZ != z) {
			ans = min(ans, mid);
			en = mid - 1; 
		}
		else st = mid + 1;
	}

	if (ans == INF) ans = -1;
	cout << ans;
	return 0;
}
