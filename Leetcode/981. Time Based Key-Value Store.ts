class TimeMap {
    myMap;
    constructor() {
        this.myMap = new Map<string,[]>();
    }

    set(key: string, value: string, timestamp: number): void {
        if(this.myMap.has(key)) {
            let arr = this.myMap.get(key);
            arr.push([timestamp, value]);
        } else {
            this.myMap.set(key, [[timestamp, value]]);
        }
    }

    get(key: string, timestamp: number): string {
        let arr = this.myMap.get(key);
        if(!arr) return "";
        
        let l=0, r=arr.length-1;
        
        if(timestamp < arr[l][0]) return "";
        if(timestamp > arr[r][0]) return arr[r][1];
        
        while(l<=r) {
            let m = Math.floor((l+r)/2);
            if(arr[m][0] === timestamp) return arr[m][1];
            else if(arr[m][0] > timestamp) r = m-1;
            else l = m+1;
        }
        
        return arr[r][1];
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * var obj = new TimeMap()
 * obj.set(key,value,timestamp)
 * var param_2 = obj.get(key,timestamp)
 */
