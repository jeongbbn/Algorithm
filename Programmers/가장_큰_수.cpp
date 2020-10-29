#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool func(string a, string b){
    int first = stoi(a+b);
    int second = stoi(b+a);
    
    if(first > second) return 1;
    else return 0;
}

vector<string>v;
string solution(vector<int> numbers) {
    string answer = "";
    for(int i=0; i<numbers.size(); i++){
        v.push_back(to_string(numbers[i]));
    }
    sort(v.begin(), v.end(), func);
    
  for(int i=0; i<v.size(); i++){
          answer+=v[i];
    }
    
    if(answer[0] == '0') answer="0";
    return answer;
}
