class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        int og = image[sr][sc];
        if(og != color) {
            image[sr][sc] = color;
            q.push({sr,sc});
        }
        
        while(!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            
            if(x-1 >= 0 && image[x-1][y] == og) {
                image[x-1][y] = color;
                q.push({x-1,y});
            }
            if(x+1 < image.size() && image[x+1][y] == og) {
                image[x+1][y] = color;
                q.push({x+1,y});
            }
            if(y-1 >= 0 && image[x][y-1] == og) {
                image[x][y-1] = color;
                q.push({x,y-1});
            }
            if(y+1 < image[x].size() && image[x][y+1] == og) {
                image[x][y+1] = color;
                q.push({x,y+1});
            }
        }
        
        return image;
    }
};
