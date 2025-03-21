class StringHash{
    public:
        int n;
        string s;
        int p1, p2;
        ll mod1, mod2;
        vector<ll> prefix1, prefix2;
        vector<ll> power1, power2;
     
        StringHash(const string &s, int p1 = 53, ll mod1 = 1e9+7)
        : s(s), p1(p1), mod1(mod1){
            n = s.size();
            prefix1.resize(n+1);
            power1.resize(n+1);
     
            power1[0] = 1;
            for(int i = 0; i < n; i++){
                prefix1[i+1] = (prefix1[i] + (s[i] - 'a' + 1) * power1[i]) % mod1;
                power1[i+1] = (power1[i]*p1) % mod1;
            }
        }
     
        ll getHash(int l, int r) const {
            ll h1 = (prefix1[r+1] + mod1 - prefix1[l]) % mod1; 
            return h1;
        }
     
        bool compareSubstr(int l1, int r1, int l2, int r2) const {
            // if((r1 - l1) != (r2 - l2)){
            //     return false;
            // }
            auto hash1 = getHash(l1, r1);
            auto hash2 = getHash(l2, r2);
     
            if(l1 < l2){
                hash1 = (hash1 * power1[l2-l1]) % mod1;
            }
            else if (l1 > l2){
                hash2 = (hash2 * power1[l1-l2]) % mod1;
            }
            return hash1 == hash2;
        }
    
        bool compareSubstr(ll hash1, int l1, int r1, int l2, int r2) const {
            if((r1 - l1) != (r2 - l2)){
                return false;
            }
            auto hash2 = getHash(l2, r2);
     
            if(l1 < l2){
                hash1 = (hash1 * power1[l2-l1]) % mod1;
            }
            else if (l1 > l2){
                hash2 = (hash2 * power1[l1-l2]) % mod1;
            }
            return hash1 == hash2;
        }
    };
     