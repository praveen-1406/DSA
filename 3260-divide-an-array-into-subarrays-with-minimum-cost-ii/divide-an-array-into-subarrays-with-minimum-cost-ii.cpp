class Solution {
public:
    typedef long long ll;
    typedef pair<ll,ll> P;

    ll minimumCost(vector<int>& nums, int k, int dist) {
        int n=nums.size();
        set<P>kmin;
        set<P>rem;
        ll sum=0;

        int i=1;
        while(i-dist <1){
            kmin.insert({nums[i],i});
            sum+=nums[i];
            if(kmin.size()>k-1){
                P temp=*kmin.rbegin();
                sum-=temp.first;
                rem.insert(temp);
                kmin.erase(temp);
            }
            i++;
        }
        ll result=LONG_MAX;
        while(i<n){
            kmin.insert({nums[i],i});
            sum+=nums[i];
            if(kmin.size()>k-1){
                P temp=*kmin.rbegin();
                sum-=temp.first;
                rem.insert(temp);
                kmin.erase(temp);
            }

            result=min(result,sum);

            P remove={nums[i-dist],i-dist};
            if(kmin.count(remove)) {
                kmin.erase(remove);
                sum-=remove.first;
                if(!rem.empty()){
                    P temp= *rem.begin();
                    kmin.insert(temp);
                    sum+=temp.first;
                    rem.erase(temp);
                }
            }else{
                rem.erase(remove);
            }


            i++;
        }
        return nums[0]+result;

    }
};