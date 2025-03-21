ll comb(ll n, ll m){
    ll answer = 1;
    m = min(m, n-m);

    for(int i = 0; i < m; i++){
        answer = (answer * (n-i)) % MOD;
        answer = (answer * mod_inverse(i+1, MOD)) % MOD;
    }

    return answer;
}