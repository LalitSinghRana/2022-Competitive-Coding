/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    const m = new Map();
    const ans = [];

    for(const s of strs) {
        const x = s.split('').sort().join('');
        if (!m.has(x)) m.set(x,[]);
        m.get(x).push(s);
    }

    for(const [k,v] of m) {
        ans.push(v);
    }

    return ans;
};
