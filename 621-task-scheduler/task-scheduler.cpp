class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // vector<int>mp(26,0);
        // for(int i=0;i<tasks.size();i++){
        //     mp[tasks[i]-'A']++;
        // }
        // int time=0;
        // priority_queue<int>pq;
        // for(int i=0;i<26;i++){
        //     if(mp[i]>0){
        //         pq.push(mp[i]);
        //     }
        // }
        // while(!pq.empty()){
        //     vector<int>temp;
        //     for(int i=1;i<=n+1;i++){
        //         if(!pq.empty()){
        //             int freq=pq.top();
        //             pq.pop();
        //             freq--;
        //             temp.push_back(freq);
        //         }
        //     }
        //     for(int &f:temp){
        //         if(f>0){
        //             pq.push(f);
        //         }
        //     }

        //     if(pq.empty()){
        //         time+=temp.size();
        //     }else{
        //         time+=n+1;
        //     }
        // }
        // return time;

        // using greedy

        vector<int>mp(26,0);
        for(char &ch:tasks){
            mp[ch-'A']++;
        } 

        sort(begin(mp),end(mp));

        int maxFreq=mp[25];
        int g=maxFreq-1;
        int idleSlots=n*g;

        for(int i=24;i>=0;i--){
            idleSlots-=min(mp[i],g);
        }
        if(idleSlots>0){
            return tasks.size()+idleSlots;
        }
        return tasks.size();


    }
};