class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int i=x,j=x+k-1;
        int m=grid.size(),n=grid[0].size();
        while(i<j){
            for(int col=y;col<y+k;col++){
                swap(grid[i][col],grid[j][col]);
            }
            i++;
            j--;
        }
        return grid;
    }
};