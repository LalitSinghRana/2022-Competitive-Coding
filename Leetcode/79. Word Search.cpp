class Solution {
public:
    vector<vector<bool>> v;
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        v.resize(n, vector<bool>(m));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == word[0] && search(board, word, i, j, 0)) return true;
            }
        }
        
        return false;
    }
    
    bool search(vector<vector<char>>& board, string &word, int i, int j, int k) {
        if(k == word.size()) return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[i].size() || board[i][j] != word[k] || v[i][j]) return false;
        
        v[i][j] = true;
        
        if(
            search(board, word, i+1, j, k+1) || 
            search(board, word, i-1, j, k+1) ||
            search(board, word, i, j+1, k+1) ||
            search(board, word, i, j-1, k+1)
        ) return true;
        
        v[i][j] = false;
        
        return false;
    }
};
