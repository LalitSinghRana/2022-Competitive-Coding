// For this challenge you will have to determine the shortest weighted path from one node to an end node.

/*
have the function WeightedPath(strArr) take strArr which will be an array of strings which models a non-looping 
weighted Graph. The structure of the array will be as follows: The first element in the array will be the number of 
nodes N (points) in the array as a string. The next N elements will be the nodes which can be anything (A, B, C .. 
Brick Street, Main Street .. etc.). Then after the Nth element, the rest of the elements in the array will be the 
connections between all of the nodes along with their weights (integers) separated by the pipe symbol (|). They will 
look like this: (A|B|3, B|C|12 .. Brick Street|Main Street|14 .. etc.). Although, there may exist no connections at 
all.

An example of strArr may be: ["4","A","B","C","D","A|B|1","B|D|9","B|C|3","C|D|4"]. Your program should return the 
shortest path when the weights are added up from node to node from the first Node to the last Node in the array 
separated by dashes. So in the example above the output should be A-B-C-D. Here is another example with strArr being 
["7","A","B","C","D","E","F","G","A|B|1","A|E|9","B|C|2","C|D|1","D|F|2","E|D|6","F|G|2"]. The output for this array 
should be A-B-C-D-F-G. There will only ever be one shortest path for the array. If no path between the first and 
last node exists, return -1. The array will at minimum have two nodes. Also, the connection A-B for example, means 
that A can get to B and B can get to A. A path may not go through any Node more than once.
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

unordered_map<string,int> sti;
unordered_map<int,string> its;
vector<vector<pair<int,int>>> g;

string getAns(vector<int> &pred, int n) {
	if(pred[n-1] == -1) return "-1";

	stack<int> st;
  int i = n - 1;
  while(i >= 0) {
    st.push(i);
    i = pred[i];
  }

	string ans;
  while(!st.empty()) {
    ans += "-" + its[st.top()];
    st.pop();
  }
  string finAns = ans.substr(1, ans.size());
  return finAns;
}

string find() {
	int n = g.size();
	vector<int> pred(n, -1);
	priority_queue<vector<int>> pq;
	pq.push({0, 0, -2});

	while(!pq.empty()) {
		auto a = pq.top();
		int i = a[1];
		pq.pop();
		
		if(pred[i] != -1) continue;
		pred[i] = a[2];
		if(i == n-1) break;
	
		for(auto [j,w] : g[i]) pq.push({-w + a[0], j, i});
	}

	return getAns(pred, n);
}


string WeightedPath(string strArr[], int size) {
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
		string s = strArr[i], s1, s2, s3;
		int j=0;
		while(s[j] != '|') s1 += s[j++];

		j++;
		while(s[j] != '|') s2 += s[j++];

		j++;
		while (j < s.size()) s3 += s[j++];

		int x = sti[s1], y = sti[s2], w = stoi(s3);
		g[x].push_back({y,w});
    g[y].push_back({x,w});
  }

  return find();
}


int main() {
	string A[] = { "4", "A", "B", "C", "D", "A|B|1", "B|D|9", "B|C|3", "C|D|4" };
	string B[] = { "7", "A", "B", "C", "D", "E", "F", "G", "A|B|1", "A|E|9", "B|C|2", "C|D|1", "D|F|2", "E|D|6", "F|G|2" };
	string C[] = { "4", "A", "B", "C", "D", "A|B|2", "C|B|11", "C|D|3", "B|D|2" };
	string D[] = { "4", "x", "y", "z", "w", "x|y|2", "y|z|14", "z|y|31" };

	cout << WeightedPath(A, sizeof(A) / sizeof(A[0])) << endl; // A-B-C-D
	cout << WeightedPath(B, sizeof(B) / sizeof(B[0])) << endl; // A-B-C-D-F-G
	cout << WeightedPath(C, sizeof(C) / sizeof(C[0])) << endl; // A-B-D
	cout << WeightedPath(D, sizeof(D) / sizeof(D[0])) << endl; // -1
	return 0;
}