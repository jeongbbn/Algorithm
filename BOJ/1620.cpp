#include <iostream>
#include <map>
#include <string>
using namespace std;

int n,q;
string arr[100005];
map<string,int>m;
int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;
	for(int i=1; i<=n; i++){
		string str;
		cin >> str;
		m[str]=i;
		arr[i] = str;
	}
	
	for(int i=0;i<q;i++){
		string str;
		cin >> str;
		
		if(str[0] >= 65 && str[0]<=90) {
			cout << m[str] << "\n";
		}
		else{
			cout << arr[stoi(str)] << "\n";
		}
	}
	return 0;
}
