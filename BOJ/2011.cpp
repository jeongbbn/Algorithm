#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

/*
	dp식 의미 : dp[x] = x자리까지의 경우의 수
	dp[3] = dp[1](2,3을 합치는 경우, 앞에 한 칸만 생각하면 됨) + dp[2](안합치는 경우, 앞에 두 칸을 생각해야됨)
*/
int main() {
	char str[5005];
	scanf("%s", str); //5005자리므로, long long을 벗어남 

	int d[5005] = { 0, };
	vector<int>arr;
	arr.push_back(0); //dp식이 1부터 시작되므로, arr엔 0을 넣어줌

	int len; for (len = 0; str[len] != '\0'; len++);

	int i = 0;
	while (len--) arr.push_back(str[i++] - '0'); //str을 int로 바꾸어주는 방법
	//arr은 025114라서 밑에 반복문 돌기가 수월함

	d[0] = 1; //왜 dp[0]=1일까? -> 1자리인 수를 생각해보자 한자리(_) 이므로,
			//신경써줘야하는건 아무것도 없는 경우 하나 뿐이다.

	for (int i = 1; i < arr.size(); i++)
	{
		//여기서 틀렸는데, d[i] += (d[i-1] % 1000000)이러면 안된다.
		// d[i]= 9999998이고, d[i-1]% 1000000 == 3인 경우엔 더하기 연산이 수행되면서
		// 1000000을 넘어버린다.
		// d[i] = (d[i] + d[i - 1]) % 1000000 이렇게 해줘야한다.
		if (arr[i] != 0) d[i] = (d[i] + d[i - 1]) % 1000000;

		//i==1일 경우는 i-2가 없다!
		if (i > 1 && arr[i - 1] * 10 + arr[i] <= 26 && arr[i - 1] * 10 + arr[i] >= 10) {
			d[i] = (d[i] + d[i - 2]) % 1000000;
		}
	}

	printf("%d\n", d[arr.size() - 1]);

}
