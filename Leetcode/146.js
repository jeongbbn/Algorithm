/**
 * @param {number} capacity
 */
var EN = 3002, ST = 3001;
var LRUCache = function(capacity) {
    this.capacity = capacity;
    this.count = 0;
    this.map = Array.from({length:3005},()=>{
        return {
            l : undefined,
            r : undefined,
            value : undefined,
        }
    });
    this.map[EN] = {
        l : ST,
        r : undefined,
        value : undefined,
    };
    this.map[ST] = {
        l : undefined,
        r : EN,
        value : undefined,
    };
};

/** 
 * @param {number} key
 * @return {number}
 */

LRUCache.prototype.update = function(key){
    //원래 자리에서 떼어낸다.
    let left = this.map[key].l;
    let right = this.map[key].r;
    this.map[left].r = right;
    this.map[right].l = left;
    
    //끝이랑 이어준다.
    let bfr = this.map[EN].l;
    this.map[bfr].r=key;
    this.map[EN].l=key;
    
    this.map[key].r = EN;
    this.map[key].l = bfr;
}

LRUCache.prototype.get = function(key) {
    
    if(this.map[key].value === undefined) return -1;
    
    this.update(key);

    return this.map[key].value;
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
    //update 
    if(this.map[key].value!== undefined) {
        this.update(key);
        this.map[key].value = value;
        return;
    }
    
    
    //insert
    if(this.capacity == this.count){
        //remove before insert
        let now = this.map[ST].r;
        let right = this.map[now].r;
        
        this.map[right].l = ST;
        this.map[ST].r = right;
            
        this.map[now] = {
            l:undefined,
            r:undefined,
            value:undefined,
        }
        this.count--;
    }
    
    //insert new one
    let left = this.map[EN].l;
    this.map[left].r = key;

    this.map[key]={
        l : left,
        r : EN,
        value : value,
    }
    
    this.map[EN].l = key;
    this.count++;

};

/** 
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
