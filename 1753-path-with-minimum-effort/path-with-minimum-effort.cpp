class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // Using Dijkstra's Algorithms
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>efforts(n,vector<int>(m,INT_MAX));
        pq.push({0,{0,0}});
        efforts[0][0]=0;
        int drow[]={-1,0,+1,0};
        int dcol[]={0,-1,0,+1};
        while(!pq.empty()){
            int effort=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==n-1 && col==m-1)    return effort;
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m ){
                    int e=abs(heights[nrow][ncol]-heights[row][col]);
                    int me=max(effort,e);
                    if(me<efforts[nrow][ncol]){
                        pq.push({me,{nrow,ncol}});
                        efforts[nrow][ncol]=me;
                    }
                }
            }
        }
        return -1;
    }
};