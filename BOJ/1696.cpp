#include <iostream>
using namespace std;

int cnt2;
int main() {
	int n;
	scanf("%d", &n); 

	int cnt = n / 5 + n / 25 + n / 125;
	printf("%d", cnt);

	//2 ^ a * 5 ^ b*etc 구조로, min(a, b)만큼 0이 있는데,
	//팩토리얼이니까 5보다는 2가 많겠지?
	//그래서 5로 나눠주는거야
	//	왜 팩토리얼 계산안해줘도 되냐면
	//	어차피 5로 나눠지면 2도 있잖아 아 54321이지 
	//	25는 2524...54321이니까 25로도 나눠주는거고
	//	그래서 그래
}	
