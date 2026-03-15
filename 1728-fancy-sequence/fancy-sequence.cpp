class Fancy {
    typedef long long ll;

    ll M=1e9+7;

    ll power(ll a,ll b){                //Binary exp
        if(b==0)    return 1;
        ll half=power(a,b/2);
        ll result=(half*half)%M;
        if(b%2==1){
            result=(result*a)%M;
        }
        return result;
    }

    vector<ll>seq;
    ll add=0;
    ll mul=1;
public:
    Fancy() {
        
    }
    
    void append(int val) {
        ll x=((val-add)%M+M)*power(mul,M-2)%M;   //Fermet Little Theorem
        seq.push_back(x);
    }
    
    void addAll(int inc) {
        add=(add+inc)%M;
    }
    
    void multAll(int m) {
        add=(add*m)%M;
        mul=(mul*m)%M;
    }
    
    int getIndex(int idx) {
        if(idx>=seq.size()){     return -1;}
        return (seq[idx]*mul+add)%M;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */