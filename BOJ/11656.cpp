#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string>v;
int main() {
	string str;
	cin >> str;
	for (int p = 0; p < str.size(); p++) v.push_back(str.substr(p));
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) cout << v[i] << "\n";
	return 0;
}
