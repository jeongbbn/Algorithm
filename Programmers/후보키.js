/*
[1]
  후보키가 되면, 그걸 빼줘야한다. 
  ex) 후보키 000001
        x   000101 
      >> x는 선택할 수 없다.
      
 따라서 이걸 비트 마스크로 하면 된다.
 (key === (key & now))이면, 포함되어있다는 뜻이다.
  
[2]
백트래킹으로 조합을 만들 때는 idx랑 cnt랑 헷갈리지 않도록 주의하자.

void backtracking(int cnt, int idx) {
	if (cnt == m) {
		//조건 만족시 해야될 일 적음
		return;
	}
	for (int i = idx; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true; //상태변화
			backtracking(cnt + 1, i); 
			visited[i] = false; //원상복구
		}
	}
}


*/
let N, M;
let pkmap = new Map();

function func(len, k, relation, visited, cnt){
    if(cnt == len){
        for(let [key, value] of pkmap){
            if(key === (key & visited)) return; 
        }
        
        let map = new Map();
        for(let i=0; i<N; i++){
            let tmp = "";
            for(let j=0; j<M; j++){
                if(!(visited & (1<<j))) continue;
                tmp += relation[i][j] + ","; 
            }
            if(map.has(tmp)) return;
            map.set(tmp, 0);
        }
        pkmap.set(visited, 0);
        return;
    }

    for(let i = k; i < M; i++){
        if(visited & (1<<i)) continue;
        func(len, i+1, relation, visited | (1<<i), cnt+1);
    }
}

function solution(relation) {
    N = relation.length;
    M = relation[0].length;
    
    for(let len=1; len<=M; len++){
       func(len, 0, relation, 0, 0);
    }
    return pkmap.size;
}
