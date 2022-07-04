/**
 * The knows API is defined in the parent class Relation.
 * isBadVersion(version: number): boolean {
 *     ...
 * };
 */

var solution = function(isBadVersion: any) {

    return function(n: number): number {
        let l: number = 1;
        let r: number = n;
        
        while(l<=r) {
            let m: number = Math.floor(r - (r-l)/2);
            if( isBadVersion(m) && (m === 1 || !isBadVersion(m-1)) ) return m;
            else if( isBadVersion(m) && isBadVersion(m-1)) r = m-1;
            else l = m+1;
        }
        
        return 1;
    };
};
