class Solution {
public:
    int minOperations(string s) {
        int changes=0;
        for(int i=0;i<s.length();i++){
            if((s[i]-'0')!=(i%2))     changes++;
        }
        return (changes <= (s.length()-changes))? changes : (s.length()-changes);
    }
};