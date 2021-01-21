#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int n, arr[50005], k;
vector<int>v;

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	scanf("%d", &k);

	int sum = 0;
	for (int i = 0; i < k; i++)
		sum += arr[i];

	v.push_back(sum);

	int st = 0; 
	for (int en = k; en < n; en++)
	{
		sum += arr[en];
		sum -= arr[st++];
		v.push_back(sum);
	}
	

}
