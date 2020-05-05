#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
/*
참고할 것
https://github.com/encrypted-def/BOJ/blob/master/2436.cpp
갓킹독님 풀이.. 이렇게 푸는게 맞는 것 같다.
*/
int main() {
	long long a ,b;
	scanf("%lld%lld", &a, &b);
	long long limit = b / a;
	/*
		6 | x  y 
	      -------
		    a  b  180

		6*a*b=180을 이용
		a*b=30(limit)

		a*b==30이므로, a에 1부터 30까지 넣어가며 a,b를 구함
		여기서 30까지 넣을 필요없음 √30까지만 넣어주면 됨
		왜냐면 1 30, 2 15, 3 10, 5 6, 6 5, 10 3, 15 2, 30 1
									 ㄴ나왔던게 또 나온다.
 	*/


	long long ans1, ans2;

	for (long long i = 1; i*i <= limit; i++)
	{
		if (limit % i != 0) continue;  //a*b==30에서 a가 4일 가능성은 0
		
		bool flag = 0;
		for (int j = 2; j*j <= i; j++) //a b의 최대 공약수는 1이어야한다.
		{								//a의 약수 중 b로 나뉘는게 있나 확인
			if (i%j != 0) continue;  //a의 약수가 아니면 넘어간다
			if ((limit / i) % j == 0) { //b(limit/i)가 a의 약수(j)로 나누어 떨어지면
				flag = 1; break;		//이번에 선택한 a, b는 잘못되었다는 뜻
			}
		}//gcd를 이용해서 풀면, 갓갓킹독님 풀이와 같아진다.

		if (flag) continue; 
		ans1 = i * a, ans2 = (limit / i) * a;
	
		//if (minsum > tmp1 + tmp2) {
// 			minsum = tmp1 + tmp2;
// 			ans1 = tmp1;
// 			ans2 = tmp2;
// 		}
		// 최솟값 찾는게 없어도 되는 이유 : 어차피 답은 마지막에서 나온다
	}

	printf("%lld %lld", ans1, ans2);
}
