// For this challenge you will have to determine the shortest path from one node to an end node.

/*
have the function ShortestPath(strArr) take strArr which will be an array of strings which models a non-looping Graph. The 
structure of the array will be as follows: The first element in the array will be the number of nodes N (points) in the 
array as a string. The next N elements will be the nodes which can be anything (A, B, C .. Brick Street, Main Street .. 
etc.). Then after the Nth element, the rest of the elements in the array will be the connections between all of the nodes. 
They will look like this: (A-B, B-C .. Brick Street-Main Street .. etc.). Although, there may exist no connections at all.

An example of strArr may be: ["4","A","B","C","D","A-B","B-D","B-C","C-D"]. Your program should return the shortest path 
from the first Node to the last Node in the array separated by dashes. So in the example above the output should be A-B-D. 
Here is another example with strArr being ["7","A","B","C","D","E","F","G","A-B","A-E","B-C","C-D","D-F","E-D","F-G"]. The 
output for this array should be A-E-D-F-G. There will only ever be one shortest path for the array. If no path between the 
first and last node exists, return -1. The array will at minimum have two nodes. Also, the connection A-B for example, means 
that A can get to B and B can get to A.
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
using namespace std;


unordered_map<string,int> sti;
unordered_map<int,string> its;
vector<vector<int>> g;

string find() {
  int n = g.size();
  vector<int> pred(n, -1);
  queue<int> q;
  q.push(0);
  pred[0] = -2;

  while(!q.empty()) {
    int i = q.front();
    q.pop();
    
    if(i == n-1) break;

    for(auto x : g[i]) {
      if(pred[x] == -1) {
        q.push(x);
        pred[x] = i;
      }
    }
  }

  if(pred[n-1] == -1) return "-1";

  stack<int> st;
  string ans;
  int i = n - 1;
  while(i >= 0) {
    st.push(i);
    i = pred[i];
  }

  while(!st.empty()) {
    ans += "-" + its[st.top()];
    st.pop();
  }
  string finAns = ans.substr(1, ans.size());
  return finAns;
}

string ShortestPath(string strArr[], int size) {
  int n = stoi(strArr[0]);
  g.clear();
  sti.clear();
  its.clear();
  g.resize(n);

  for(int i=1; i<=n; i++) {
    sti[strArr[i]] = i-1;
    its[i - 1] = strArr[i];
  }

  for(int i=n+1; i<size; i++) {
    string s = strArr[i], s1, s2;
    int j=0;
    while(s[j] != '-') s1 += s[j++];

    j++;
    while(j < s.size()) s2 += s[j++];

    int x = sti[s1], y = sti[s2];
    g[x].push_back(y);
    g[y].push_back(x);
  }

  return find();
}

int main() {
	string A[] = { "4", "A", "B", "C", "D", "A-B", "B-D", "B-C", "C-D" };
	string B[] = { "7", "A", "B", "C", "D", "E", "F", "G", "A-B", "A-E", "B-C", "C-D", "D-F", "E-D", "F-G" };
	string C[] = { "5", "A", "B", "C", "D", "F", "A-B", "A-C", "B-C", "C-D", "D-F" };
	string D[] = { "4", "X", "Y", "Z", "W", "X-Y", "Y-Z", "X-W" };
	string E[] = { "7", "C", "B", "A", "D", "E", "G", "F", "A-B", "B-E", "E-G", "C-D", "D-B", "D-E", "E-F" };
	string F[] = { "9", "Z", "B", "C", "D", "R", "A", "Y", "Q", "E", "A-Z", "A-R", "Z-Y", "Z-C", "C-B", "Y-Q", "Q-D", "D-E", "R-E" };
	string G[] = { "5", "N1", "N2", "N3", "N4", "N5", "N1-N3", "N3-N4", "N4-N5", "N5-N2", "N2-N1" };

	cout << ShortestPath(A, sizeof (A)/sizeof(A[0])) << endl; // A-B-D
	cout << ShortestPath(B, sizeof(B) / sizeof(B[0])) << endl; // A-E-D-F-G
	cout << ShortestPath(C, sizeof(C) / sizeof(C[0])) << endl; // A-C-D-F
	cout << ShortestPath(D, sizeof(D) / sizeof(D[0])) << endl; // X-W
	cout << ShortestPath(E, sizeof(E) / sizeof(E[0])) << endl; // C-D-E-F
	cout << ShortestPath(F, sizeof(F) / sizeof(F[0])) << endl; // Z-A-R-E
	cout << ShortestPath(G, sizeof(G) / sizeof(G[0])) << endl; // N1-N2-N5
	
	return 0;
}
