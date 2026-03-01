class Solution {
public:
    int minPartitions(string n) {
        int mdigit=0;
        for(int i=0;i<n.length();i++){
            mdigit=max(mdigit,n[i]-'0');
        }
        return mdigit;
    }
};