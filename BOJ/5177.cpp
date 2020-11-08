#include <iostream>
#include <regex>
#include <string>
using namespace std;

string func(string s){
	//대문자->소문자
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	
	//1. 공백 여러개 -> 하나
	regex r1(R"(\s+)"); //R을 쓰려면 ( )로 닫아줘야함
	s = regex_replace(s,r1," ");
	
	//2. 여는괄호 통일
	regex r2(R"([({\[])");
	s = regex_replace(s,r2,"(");
	
	//3. 닫는괄호 통일
	regex r3(R"([\])}])");
	s = regex_replace(s,r3,")");
	
	//4. ,와 ;통일
	regex r4(R"(;)");
	s = regex_replace(s,r4,",");
	
	//5. ( 앞뒤 공백 제거
	regex r5(R"(\s?\(\s?)");
	s = regex_replace(s,r5,"(");

	//6. ) 앞뒤 공백 제거
	regex r6(R"(\s?\)\s?)");
	s = regex_replace(s,r6,")");

	//7. , 앞뒤 공백 제거
	regex r7(R"(\s?\,\s?)");
	s = regex_replace(s,r7,",");
	
	//8. . 앞뒤 공백 제거
	regex r8(R"(\s?\.\s?)");
	s = regex_replace(s,r8,".");

	//9. : 앞뒤 공백 제거
	regex r9(R"(\s?\:\s?)");
	s = regex_replace(s,r9,":");

	return s;
}

int n;
int main() {
	scanf("%d ", &n);
	for (int tc = 1; tc <= n; tc++) {
		string a, b;
		getline(cin, a); getline(cin, b);

		string res1, res2;
		res1 = func(a); res2 = func(b);

		if (res1 == res2) printf("Data Set %d: equal\n\n",tc);
		else printf("Data Set %d: not equal\n\n", tc);
	}
	return 0;
}
