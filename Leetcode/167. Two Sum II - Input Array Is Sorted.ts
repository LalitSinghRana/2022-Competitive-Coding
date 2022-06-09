function twoSum(numbers: number[], target: number): number[] {
    let i:number = 0, j:number = numbers.length -1;
    
    while(i<j) {
        let x:number = numbers[i] + numbers[j];
        if(x == target) return [i+1, j+1];
        else if(x > target) j--;
        else i++;
    }
    
    return [-1,-1];
};
