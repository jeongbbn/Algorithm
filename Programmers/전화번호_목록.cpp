/*
프로그래머스 전화번호 목록
*/


#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    map<string,int>m;
    bool answer = true;
    
    for(int i=0; i< phone_book.size(); i++){
        if(m.find(phone_book[i]) != m.end()) {return 0;}
        m.insert({phone_book[i], i });
    }
    
    for(int i = 0; i < phone_book.size(); i++){
        int len = phone_book[i].size();
        string tmp ="";
        for(int j = 0; j < len; j++){
            tmp+=phone_book[i][j];
            if(m.find(tmp) != m.end() && m[tmp] != i)  return 0;
        }
    }
    return answer;
}
