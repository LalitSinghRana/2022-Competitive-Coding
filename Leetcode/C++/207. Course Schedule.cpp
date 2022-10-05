class Solution {
public:
    vector<int> t;
    vector<vector<int>> adjMat;
    bool flag = true;
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adjMat.resize(numCourses, vector<int>());
        t.resize(numCourses);
        
        for(int i=0; i<prerequisites.size(); i++) {
            adjMat[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i=0; i<numCourses; i++) {
            process(i);
            if(!flag) return false;
        }
        
        return true;
    }
    
    bool process(int num) {
        if(t[num] == 2) return true;
        else if(t[num] == 1) return false;
        
        t[num] = 1;
        
        for(int i=0; i<adjMat[num].size(); i++) {
            if(!process(adjMat[num][i])) flag = false;
            if(!flag) return false;
        }
        
        t[num] = 2;
        return true;
    }
};
