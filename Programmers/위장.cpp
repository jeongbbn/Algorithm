/*
프로그래머스 위장

*/

#include <string>
#include <vector>
#include <map>
using namespace std;

map<string,int>m;
vector<int>v;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    for(int i=0;i<clothes.size(); i++){
        if(m.find(clothes[i][1]) != m.end()){
            int idx = m[clothes[i][1]];
            v[idx]++;
        }
        else{
            m.insert({clothes[i][1], v.size()});
            v.push_back(1);
        }
    }
    int sum = 1;
    for(int i=0; i<v.size(); i++){
        sum*=(v[i]+1);
    }
    sum--;
    answer=sum;
    
    return answer;
}
