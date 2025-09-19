class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);

        while(!q.empty()){
            string word=q.front().first;
            int dis=q.front().second;
            if(endWord==word)   return dis;
            q.pop();
            for(int i=0;i<word.size();i++){
                int c=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,dis+1});
                        st.erase(word);
                    }
                }
                word[i]=c;
            }
        }
        return 0;
    }
};