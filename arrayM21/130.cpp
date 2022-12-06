// https://leetcode.com/problems/surrounded-regions/description/

// 130. Surrounded Regions

// Approach:
// the idea here is that every thing that touches the wall will not be converted
// thus we have to find elements that touching the wall,
// 1. start off at the wall, and call a dfs function
// 2. the dfs function will find all the elements that contacted the wall
// 3. now convert 'O' which not contacted wall to 'X'
// 4. and revert back to 'O' those touched wall.


class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<int>>& check, int i,int j){
        // out of bonds
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()){
            return;
        }

        // current position is valid / already visited
        if(board[i][j]=='X' || check[i][j]==1){
            return;
        }
        board[i][j] = '*';
        check[i][j] = 1;
        int dir[] = {0,1,0,-1,0};
        int k,r,c;
        for(k=0;k<4;k++){   
            r = i+dir[k];
            c = j+dir[k+1];
            dfs(board,check,r,c);
        }
    }
    void solve(vector<vector<char>>& board) {
        int i,n=board.size(),m=board[0].size(),j;
        vector<vector<int>> check(n,vector(m,0));
        for(i=0;i<m;i++){
            dfs(board, check, 0,i);
            dfs(board, check, n-1,i);
        }
        for(i=1;i<n-1;i++){
            dfs(board,check,i,0);
            dfs(board,check,i,m-1);
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='*'){
                    board[i][j]='O';
                }
            }
        }
    }
};