ll inverse(ll n, ll mod){
    ll ans = 1;
    ll a = n;
    ll b = mod - 2;
    while(b){
        if(b & 1){
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}