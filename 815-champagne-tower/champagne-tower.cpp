class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>a(102,vector<double>(102,0));
        a[0][0]=(double)poured;
        for(int r=0;r<=query_row;r++){
            for(int c=0;c<=r;c++){
                double q=(a[r][c]-1.0)/2.0;
                if(q>0){
                    a[r+1][c]+=q;
                    a[r+1][c+1]+=q;
                }
            }
        }
        return min(1.0,a[query_row][query_glass]);
    }
};