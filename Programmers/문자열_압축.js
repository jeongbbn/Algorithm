/*
  문자열을 몇 개를 기준으로 잘랐을 때, 길이가 최소가 되는지 구해야된다.
  따라서 s.length<=1000 이므로, 직접 for문을 순회하며 몇 개로 잘랐을 때 최소 길이가 되는지 알아볼 필요가 있다.
  
  이 때, s.length >= 2가 되면 s를 제대로 자를 수 없게 되므로 for문은 s.length/2까지만 돌면 된다.
  
  사용한 js 문법---------
  substr(idx, cnt) : idx부터 cnt개까지 자름
  min, max : Math.min(A,B);
*/

function solution(s) {
    var answer = s.length;
    
    for(let len=1; len<=s.length/2; len++){
        const arr=[];
        
        let idx = 0;
        while(1){
            if(idx >= s.length) break;
            arr.push(s.substr(idx, len));
            idx += len;
        }
        
        let ret = "";
        let bfr = arr[0];
        let cnt = 1;
        for(let i=1; i<arr.length; i++){
            if(bfr !== arr[i]){
                if(cnt === 1) cnt = "";
                ret += (cnt+bfr);
                
                bfr = arr[i];
                cnt = 1;
            }
            else cnt++;
        }
        if(cnt === 1) cnt = "";
        ret += (cnt+bfr);
        
        answer = Math.min(answer, ret.length);
    }
    return answer;
}
