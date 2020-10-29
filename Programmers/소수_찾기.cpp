/*
  프로그래머스 소수 찾기
*/
#include <string>
#include <vector>
#include <map>
using namespace std;

bool visit[10];
int answer,N;
string s, str;
map<int,bool>m;

void dfs(int k, string tmp, int n){
    if(k==n){
        int w = stoi(tmp);
        if(m.find(w) != m.end()) return;

        printf("%d ",w);
        bool flag =0;
        if(w==1 || w==0)  flag = 1;
        for(int i=2; i*i<=w; i++){
            if(w%i==0) {flag=1; break;}
        }
        if(!flag) answer++;
        m.insert({w,1});
        return;
    }
    for(int i=0; i<N; i++){
        if(visit[i]) continue;
        visit[i]=1;
        dfs(k+1, tmp+str[i],n);
        visit[i]=0;
    }
}

int solution(string numbers) {
    N = numbers.size();
    str = numbers;
    for(int i=1;i<=N;i++ )
        dfs(0,s,i);
    return answer;
}
