#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
	al : binarySearch (lower_bound, upper_bound)
	=> 이분탐색으로 끝내기에는 동일한 값이 여러개 들어갈 수 있다.
	ds : array
	trick : 1) A,B,C,D을 한번에 모두 보겠다는 것 말고, A+B, C+D를 전처리해준 후,
			   이분탐색을 통해 A+B의 상대값이 C+D 조합에 있는지 확인한다.
			2) CD 조합에 -(A+B)가 없는 경우도 있다. -> 조건문을 통해 걸러준다.
*/

int n;
ll A[4005], B[4005], C[4005], D[4005], ans;
vector<ll>arr1, arr2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> A[i] >> B[i] >> C[i] >> D[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr1.push_back(A[i] + B[j]);
			arr2.push_back(C[i] + D[j]);
		}
	}

	sort(arr2.begin(), arr2.end());

	for (int i = 0; i < arr1.size(); i++)
	{
		ll x = -arr1[i];
		if (!binary_search(arr2.begin(), arr2.end(), x)) continue;

		ll st = lower_bound(arr2.begin(), arr2.end(), x) - arr2.begin();
		ll en = upper_bound(arr2.begin(), arr2.end(), x) - arr2.begin();
		ans += (en - st);
	}

	cout << ans;
}
