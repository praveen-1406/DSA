class Solution {
private:
    static const long long HASH_VAL=60013;
    long long hashCoordinates(long long x,long long y){
        return y+HASH_VAL*x;
    }
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long>obst;
        for(auto &obs:obstacles){
            obst.insert(hashCoordinates(obs[0],obs[1]));
        }
        vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        int maxi=0;
        int curDir=0;
        int x=0,y=0;
        for(auto& com:commands){
            if(com==-1){
                curDir=(curDir+1)%4;
            }else if(com==-2){
                curDir=(curDir-1+4)%4;
            }else{
                for(int i=0;i<com;i++){
                    int newx=x+dir[curDir][0];
                    int newy=y+dir[curDir][1];
                    if(obst.contains(hashCoordinates(newx,newy))){
                        break;
                    }
                    x=newx;
                    y=newy;
                }
                maxi=max(maxi,x*x+y*y);
            }
        }
        return maxi;
    }
};