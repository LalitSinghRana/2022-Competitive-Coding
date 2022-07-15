/**
 * Definition for Node.
 * class Node {
 *     val: number
 *     neighbors: Node[]
 *     constructor(val?: number, neighbors?: Node[]) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.neighbors = (neighbors===undefined ? [] : neighbors)
 *     }
 * }
 */
let myMap;
function cloneGraph(node: Node | null): Node | null {
    myMap = new Map<number, Node>();
    return helper(node);
};

const helper = (node: Node | null): Node | null => {
    if(!node) return null;
    if(myMap.has(node.val)) return myMap.get(node.val);
    
    let a = new Node(node.val);
    myMap.set(a.val,a);
    
    for(let i=0; i<node.neighbors.length; i++) a.neighbors.push(helper(node.neighbors[i]));
    
    return a;
}
