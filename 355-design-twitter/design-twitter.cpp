class Twitter {
    int time;
    unordered_map<int,unordered_set<int>>following;
    unordered_map<int,vector<pair<int,int>>>posts;   // user, (time,postId)
public:
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;  //min-heap
        for(auto i:posts[userId]){
            pq.push(i);
            if(pq.size()>10)    pq.pop();
        }
        for(auto f:following[userId]){
            for(auto i:posts[f]){
                pq.push(i);
                if(pq.size()>10)    pq.pop();
            }
        }
        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */