void genSubsets(const vector<ll>& v, vector<ll>& subs_sum_v, ll& sum, int index){
    subs_sum_v.push_back(sum);

    for(int i = index; i < static_cast<int>(v.size()); ++i){
        sum += v[i];
        genSubsets(v, subs_sum_v, sum, i+1);
        sum -= v[i];
    }
}

ll meet_in_the_middle(){
    vector<ll> lo(n/2);
    vector<ll> hi(n-n/2);
    
    for(int i = 0; i < n/2; i++){
        cin >> lo[i];
    }
    for(int i = n/2; i < n; i++){
        cin >> hi[i-n/2];
    }
    
    vector<ll> subs_sum_lo;
    subs_sum_lo.reserve(pow(2, n/2));
    vector<ll> subs_sum_hi;
    subs_sum_hi.reserve(pow(2, n-n/2));
    
    ll sum = 0;
    genSubsets(lo, subs_sum_lo, sum, 0);
    sum = 0;
    genSubsets(hi, subs_sum_hi, sum, 0);
    
    sort(subs_sum_lo.begin(), subs_sum_lo.end());
    
    ll ans = 0;
    for(ll v:subs_sum_hi){
        auto it_lo = lower_bound(subs_sum_lo.begin(), subs_sum_lo.end(), target-v);
        auto it_hi = upper_bound(subs_sum_lo.begin(), subs_sum_lo.end(), target-v);
    
        if(it_lo != subs_sum_lo.end()){
            ans += it_hi - it_lo;
        }
    }

    return ans;
}