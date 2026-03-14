class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0)      return false;
        //min heap
        map<int,int>mp;
        for(auto i:hand){
            mp[i]++;
        }
        // int pre=-1,cur=-1;
        // int ind=0;
        // auto it=mp.begin();
        // while(!mp.empty()){
        //         cur=(*it).first;
        //         // if(cur==pre && mp.size()>=2){
        //         //     it++;
        //         //     cur=(*it).first;
        //         // }

        //         if(ind%groupSize==0){
        //             pre=cur;
        //             mp[pre]--;
        //             it=mp.begin();
        //         }else{
        //             if(cur!=pre+1)  return false;
        //             pre=cur;
        //             mp[pre]--;
        //         }
        //         it++;
        //         if(mp[cur]==0)  mp.erase(cur);
        //         ind++;
        //         // if(it==mp.end()){
        //         //     it=mp.begin();
        //         // }
        // }
        int pre=-1,cur=-1,ind=0;
        while(!mp.empty()){
            for(auto i:mp){
                cur=i.first;
                if(pre!=-1 && cur!=pre+1)   return false;
                mp[cur]--;
                pre=cur;
                if(mp[pre]==0)  mp.erase(pre);

                ind++;
                if(ind%groupSize==0){
                    pre=cur=-1;
                    break;
                }
            }
        }

        return true;
    }
};