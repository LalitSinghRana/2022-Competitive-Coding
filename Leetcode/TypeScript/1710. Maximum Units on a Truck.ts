function maximumUnits(boxTypes: number[][], truckSize: number): number {
    boxTypes.sort((a,b) => b[1]-a[1]);
    let ans: number = 0;
    for(let i=0; i<boxTypes.length && truckSize>0; i++) {
        if(truckSize >= boxTypes[i][0]) ans += boxTypes[i][0]*boxTypes[i][1];
        else ans += truckSize*boxTypes[i][1];
        
        truckSize -= boxTypes[i][0];
    }
    
    return ans;
};
