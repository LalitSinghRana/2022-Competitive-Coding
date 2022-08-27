// For this challenge you will determine what nodes are farthest apart.

/*
have the function FarthestNodes(strArr) read strArr which will be an array of hyphenated letters representing paths 
between those two nodes. For example: ["a-b","b-c","b-d"] means that there is a path from node a to b (and b to a), 
b to c, and b to d. Your program should determine the longest path that exists in the graph and return the length of 
that path. So for the example above, your program should return 2 because of the paths a-b-c and d-b-c. The path 
a-b-c also means that there is a path c-b-a. No cycles will exist in the graph and every node will be connected to 
some other node in the graph.
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
vector<vector<int>> g;

int find() {
  int n = g.size(), ans = 0;
  
  for (int i = 0; i < n; i++) {
    vector<bool> vis(n);
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    int cnt = -1;

    while(!q.empty()) {
      cnt++;
      int size = q.size();
      while(size--) {
        int j = q.front();
        q.pop();
        for(auto x : g[j]) {
            if(!vis[x]) {
                vis[x] = 1;
                q.push(x);
            }
        }
      }
    }

    ans = max(ans, cnt);
    if(ans >= n-1) break;
  }

  return ans;
}

int FarthestNodes(string strArr[], int size) {
  int k = 0;
  g.clear();
  sti.clear();
  its.clear();

  for(int i=0; i<size; i++) {
    string s = strArr[i], s1, s2;
    int j=0;
    while(s[j] != '-') s1 += s[j++];

    j++;
    while(j < s.size()) s2 += s[j++];

    if(sti.find(s1) == sti.end()) {
      sti[s1] = k;
      its[k] = s1;
      g.push_back({});
      k++;
    }

    if(sti.find(s2) == sti.end()) {
      sti[s2] = k;
      its[k] = s2;
      g.push_back({});
      k++;
    }

    int x = sti[s1], y = sti[s2];
    g[x].push_back(y);
    g[y].push_back(x);
  }

  return find();
}

int main() 
{
	string A[] = { "a-b","b-c","b-d" };
	string B[] = { "b-e","b-c","c-d","a-b","e-f" };
	string C[] = { "b-a","c-e","b-c","d-c" };

	cout << FarthestNodes(A, sizeof(A) / sizeof(A[0])) << endl; // 2
	cout << FarthestNodes(B, sizeof(B) / sizeof(B[0])) << endl; // 4
	cout << FarthestNodes(C, sizeof(C) / sizeof(C[0])) << endl; // 3

	return 0;
}
