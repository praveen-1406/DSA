class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int cnt=0;
        int m=grid.size();
        int n=grid[0].size();

        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(row>0)       grid[row][col]+=grid[row-1][col];
                if(col>0)       grid[row][col]+=grid[row][col-1];
                if(row>0 && col>0)  grid[row][col]-=grid[row-1][col-1];

                if(grid[row][col]<=k)   cnt++;
                else    break;
            }
        }
        return cnt;
    }
};