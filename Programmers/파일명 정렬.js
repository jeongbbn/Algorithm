
function solution(files) {
    var answer = [];
    const regex = /([\D]+)(\d{1,5})(.*)/

    const sliceStr = (str)=>{
        const match = regex.exec(str);
        let head = match[1].toUpperCase() || null;
        let numbers = parseInt(match[2]) || null;
        let tail = match[3].trim().toUpperCase() || "";
        return [head, numbers, tail];
    }

    files.sort((x, y)=>{
        const [xHead, xNumber, xTail] = sliceStr(x);
        const [yHead, yNumber, yTail] = sliceStr(y);
        if(xHead < yHead) return -1;
        if(xHead > yHead) return 1;
        
        if(xNumber < yNumber) return -1;
        if(xNumber > yNumber) return 1;

        return 0;
    })
    
    return files;
}
