#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

vector<string> parsing(string s, char delimiter[]){
	vector<string>v;
	char *res;
	res = strtok((char *) s.c_str(), delimiter);
	while(res!=NULL){
		string tmp="";
		tmp+=res;
		res = strtok(NULL, delimiter);
		v.push_back(tmp);
	}
	return v;
}

int tc;
char deli[] = " ";

int main() {
	scanf("%d ",&tc);
	while(tc--){
		map<string,bool>m;
		vector<string>animal;
		string str; 
		getline(cin, str);
		animal = parsing(str, deli);
	
		while(1){
			string tmp;
			vector<string>v;
			getline(cin, tmp);
			
			//what does fox says?
			if(tmp.find('?')!=string::npos) break;
			v = parsing(tmp, deli);
			m.insert({v[2],1});
		}
	
		for(int i=0;i<animal.size(); i++){
			if(m.find(animal[i])==m.end()) 
			cout << animal[i] << " ";
		}
	}
	return 0;
}
