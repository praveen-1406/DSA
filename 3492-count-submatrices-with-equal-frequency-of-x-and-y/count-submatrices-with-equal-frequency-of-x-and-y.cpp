class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<pair<int,int>>>result(m,vector<pair<int,int>>(n,{0,0}));   // {x,y}
        int count=0;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]=='X')     result[row][col].first++;
                else if(grid[row][col]=='Y')    result[row][col].second++;
                if(row>0){
                    result[row][col].first+=result[row-1][col].first;
                    result[row][col].second+=result[row-1][col].second;
                }
                if(col>0){
                    result[row][col].first+=result[row][col-1].first;
                    result[row][col].second+=result[row][col-1].second;
                }
                if(row>0 && col>0){
                    result[row][col].first-=result[row-1][col-1].first;
                    result[row][col].second-=result[row-1][col-1].second;
                }
                if(result[row][col].first>0 && result[row][col].first==result[row][col].second)     count++;
            }
        }
        return count;
    }
};