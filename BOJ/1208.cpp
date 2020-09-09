#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n, s, arr[45], sum;
bool visit[45];

vector<int>A, B;

void dfs(int st, int en, int fin, int k, vector<int> &tmp) {
	if (k == fin) {
		tmp.push_back(sum);
		return;
	}

	for (int i = st; i <= en; i++)
	{
		if (visit[i]) continue;
		visit[i] = 1;
		sum += arr[i];
		dfs(i, en, fin, k + 1, tmp);
		sum -= arr[i];
		visit[i] = 0;
	}

}
int main() {
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int a = n / 2 + 1;
	int b = n - (n / 2 - 1);

	for (int i = 0; i <= a; i++)
		dfs(0, n / 2, i, 0, A); 

	for (int i = 0; i <= b; i++) 
		dfs(n / 2 + 1, n - 1, i, 0, B);

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int l = 0, r = B.size();
	r -= 1;

	long long ans = 0;
	while (l < A.size() && r >= 0) {
		int lTmp = A[l];
		int rTmp = B[r];

		if (lTmp + rTmp == s) {
			long long lCnt = 0;
			while (l < A.size() && A[l] == lTmp) {
				lCnt++;
				l++;
			}

			long long rCnt = 0;
			while (r >= 0 && B[r] == rTmp) {
				rCnt++;
				r--;
			}

			ans += rCnt * lCnt;
		}

		else if (lTmp + rTmp > s) {
			r--;
		}
		else l++;
	}
	if (s == 0) ans -= 1;
	printf("%lld",ans);
}
