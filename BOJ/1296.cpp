#include <bits/stdc++.h>
using namespace std;

string ohminsik;
int n;

void func(string s, int *arr) {
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'L') arr[0]++;
		else if (s[i] == 'O') arr[1]++;
		else if (s[i] == 'V') arr[2]++;
		else if (s[i]== 'E') arr[3]++;
	}
}

int main() {
	cin >> ohminsik;
	int name[4] = { 0, };
	func(ohminsik, name);

	cin >> n;
	vector<string>v;
	while (n--) {
		string str;
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end());

	int ans = -1;
	string ansStr = "";

	for (int i = 0; i < v.size(); i++)
	{
		int arr[4] = { 0, };
		func(v[i], arr);
		int L = name[0] + arr[0];
		int O = name[1] + arr[1];
		int V = name[2] + arr[2];
		int E = name[3] + arr[3];

		int tmp = ((L + O)*(L + V)*(L + E)*(O + V)*(O + E)*(V + E)) % 100;
		if (ans < tmp) {
			ans = tmp;
			ansStr = v[i];
		}
	}
	cout << ansStr;
}
