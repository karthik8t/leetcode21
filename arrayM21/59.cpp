// https://leetcode.com/problems/spiral-matrix-ii/
// 59. Spiral Matrix II


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n,vector(n,0));
        int i,j,curr = 1;
        int len, row=n,col=n;
        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int k=0;
        int pos[2] = {0,-1};
        while(curr<=n*n){
            if(k==0 || k==2){
                len = row;
            }
            else{
                len = col;
            }
            for(i=0;i<len;i++){
                pos[0]+= dir[k][0];
                pos[1]+= dir[k][1];
                result[pos[0]][pos[1]] = curr;
                curr++;
            }
            if(k==0 || k==2){
                col--;
            }
            else{
                row--;
            }
            k = (k+1)%4;
        }
        return result;
    }
};