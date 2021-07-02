/*
1) 우선 문자열을 비트로 변환해준다.
"java backend junior pizza 150" 
00 00 00 000
->
10 01 01 010

2) Map에 해당 비트를 포함하는 애들에게 score를 넣어준다.
(ex, 100000000, 000100000, 00000000, .... 100101010)

3) query에서 만난 문자열을 비트로 변환한 뒤, 해당 Map에 가서 score의 개수를 반환한다.
-> lower_bound


*/
function makeBit(arr){
    let bit = 0;
    if(arr[0] == "cpp"){
        bit |= (1<<0);
    }
    else if(arr[0] == "java"){
        bit |= (1<<1);
    }
    else if(arr[0] == "python"){
        bit |= (1<<2);
    }
    
    if(arr[1] == "backend"){
        bit |= (1<<3);
    }
    else if(arr[1] == "frontend"){
        bit |= (1<<4);
    }
    
    if(arr[2]=="junior"){
        bit |= (1<<5);
    }
    else if(arr[2] == "senior"){
        bit |= (1<<6);
    }
    
    if(arr[3]=="chicken"){
        bit |= (1<<7);
    }
    else if(arr[3] == "pizza"){
        bit |= (1<<8);
    }
    return bit;
}

function binary(list, target, st, en){
    if(st===en) return st;
    let mid = Math.floor((st+en)/2);
    
    if(list[mid] < target) return binary(list, target, mid + 1, en);
    else return binary(list, target, st, mid);
}

function solution(info, query) {
    var answer = [];
    const list = [];
    for(let i=0; i<(1<<9); i++){
        list[i] = [];
    }

    for(let i=0; i<info.length; i++){
        const arr = info[i].split(' ');
        let bit = makeBit(arr);
        let score = Number(arr[4]);
        
        for(let b=0; b<(1<<9); b++){
            if((b & bit) === b) {
                list[b].push(score);
            }
        }
    }
    
    for(let b=0; b<(1<<9); b++){
        list[b].sort((a,b) => a-b);
    }
    
    for(let i=0; i<query.length; i++){
        const arr = query[i].split(" and ");
        const tmp = arr[3].split(" ");
        arr[3] = tmp[0];
        arr[4] = tmp[1];
        
        let bit = makeBit(arr);
        const bitList = list[bit];

        let idx = binary(bitList, Number(arr[4]), 0, bitList.length);
        answer.push(bitList.length - idx);
    }    
    
    return answer;
}
