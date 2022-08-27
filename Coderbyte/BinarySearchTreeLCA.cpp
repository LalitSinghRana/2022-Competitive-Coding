// For this challenge you will attempt to find the lowest common ancestor of a binary search tree.

/*
have the function BinarySearchTreeLCA(strArr) take the array of strings stored in strArr, which will contain 3 
elements: the first element will be a binary search tree with all unique values in a preorder traversal array, the 
second and third elements will be two different values, and your goal is to find the lowest common ancestor of these 
two values. For example: if strArr is ["[10, 5, 1, 7, 40, 50]", "1", "7"] then this tree looks like the following:

For the input above, your program should return 5 because that is the value of the node that is the LCA of the two 
nodes with values 1 and 7. You can assume the two nodes you are searching for in the tree will exist somewhere in 
the tree.
*/

#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>

#include <string>
#include <vector>
#include <queue>
#include <stack>

#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> tempArr, bstArr;

TreeNode* createBST(int s, int e) {
  if(e < s) return nullptr;

  auto head = new TreeNode(tempArr[s]);
  int i = s+1;
  while(i < e) {
      if(tempArr[i] > tempArr[s]) break;
      i++;
  }
  head->left = createBST(s+1, i-1);
  head->right = createBST(i,e);

  return head;
}

int find(TreeNode* r, int x, int y) {
  if(r->val > x && r->val > y) return find(r->left, x, y);
  if(r->val < x && r->val < y) return find(r->right, x, y);

  return r->val;
}

string BinarySearchTreeLCA(string strArr[]) {    
  tempArr.clear();
  string s = strArr[0];
  
  for (int i = 1; i < s.size(); i++) {
    string s1;
    while(s[i] != ',' && s[i] != ']') s1 += s[i++];
    i++;
    tempArr.push_back(stoi(s1));
  }
  
  auto root = createBST(0, tempArr.size()-1);
  return to_string(find(root, stoi(strArr[1]), stoi(strArr[2])));
}

int main() {
	string A[] = {"[10, 5, 1, 7, 40, 50]", "1", "7"};         // 5
	string B[] = {"[6, 2, 0, 4, 3, 5, 8, 7, 9]", "2", "8"};   // 6
	string C[] = {"[6, 2, 0, 4, 3, 5, 8, 7, 9]", "2", "4"};   // 2
	string D[] = {"[2, 1]", "2", "1"};                        // 2
	string E[] = {"[6, 2, 0, 4, 3, 5, 8, 7, 9]", "3", "9"};   // 6
	string F[] = {"[6, 2, 0, 4, 3, 5, 8, 7, 9]", "0", "9"};   // 6
	string G[] = {"[6, 2, 0, 4, 3, 5, 8, 7, 9]", "0", "3"};   // 2
	string H[] = {"[6, 2, 0, 4, 3, 5, 8, 7, 9]", "0", "2"};   // 2
	string I[] = {"[6, 2, 0, 4, 3, 5, 8, 7, 9]", "5", "4"};   // 4
	string J[] = {"[6, 2, 0, 4, 3, 5, 8, 7, 9]", "9", "8"};   // 8
	cout << "calling : " << BinarySearchTreeLCA(A) << endl;
	cout << "calling : " << BinarySearchTreeLCA(B) << endl;
	cout << "calling : " << BinarySearchTreeLCA(C) << endl;
	cout << "calling : " << BinarySearchTreeLCA(D) << endl;
	cout << "calling : " << BinarySearchTreeLCA(E) << endl;
	cout << "calling : " << BinarySearchTreeLCA(F) << endl;
	cout << "calling : " << BinarySearchTreeLCA(G) << endl;
	cout << "calling : " << BinarySearchTreeLCA(H) << endl;
	cout << "calling : " << BinarySearchTreeLCA(I) << endl;
	cout << "calling : " << BinarySearchTreeLCA(J) << endl;
	return 0;
}