class Solution {
    int findMax(vector<vector<int>>& mat,int col){
        int m=mat.size();
        int maxi=-1;
        int index=-1;
        for(int i=0;i<m;i++){
            if(mat[i][col]>maxi){
                maxi=mat[i][col];
                index=i;
            }
        }
        return index;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            int maxRow=findMax(mat,mid);
            int left=(mid>0)?mat[maxRow][mid-1]:-1;
            int right=(mid<n-1)?mat[maxRow][mid+1]:-1;
            if(mat[maxRow][mid]>left && mat[maxRow][mid]>right)     return {maxRow,mid};
            else if(mat[maxRow][mid]<left)      high=mid-1;
            else    low=mid+1;
        }
        return {-1,-1};
    }
};