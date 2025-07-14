class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        
        // vector<int>left(n);
        // left[0]=1;
        // // right[n-1]=1;
        // for(int i=1;i<n;i++){
        //     if(ratings[i]>ratings[i-1])   left[i]=left[i-1]+1;
        //     else    left[i]=1;

        //     // if(ratings[n-1-i]>ratings[n-i])     right[n-1-i]=right[n-i]+1;
        //     // else    right[n-1-i]=1;
        // }
        // int sum=max(1,left[n-1]),cur=1;
        // for(int i=n-2;i>=0;i--){
        //     if(ratings[i]>ratings[i+1]){
        //         cur++;
        //         // right=cur;
        //     }else   cur=1;
        //     sum+=max(cur,left[i]);
        // }
        // return sum;

        // Optimal Solution
        int sum=1;
        int i=1;
        while(i<n){
            if(ratings[i]==ratings[i-1]) {
                sum++;
                i++;
                continue;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                sum+=peak;
                i++;
            }
            int down=1;
            while(i<n && ratings[i]<ratings[i-1]){
                sum+=down;
                down++;
                i++;
            }
            // down++;
            if(peak<down)   sum=sum-peak+down;
        }
        return sum;
    }
};