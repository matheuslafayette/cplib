ll dp[2000+3][2000+3][2][2][2];
ll solve_digit_dp(int pos, int mod, bool smaller, bool only_zero, bool is_even){
    if(pos == static_cast<int>(v.size())){
        return mod == 0;
    }
    if(dp[pos][mod][smaller][only_zero][is_even] != -1){
        return dp[pos][mod][smaller][only_zero][is_even] % MOD;
    }
    dp[pos][mod][smaller][only_zero][is_even] = 0;
    int tight = smaller ? 9 : v[pos];
    for(int i = 0; i <= tight; i++){
        bool new_is_smaller = smaller or (i < v[pos]);
        int new_mod = (mod*10 + i) % m;
        int new_only_zero = only_zero and i == 0;
        int new_is_even = new_only_zero ? is_even : !is_even;
        if(not new_only_zero and i == d and not new_is_even){
            continue;
        }
        if(not new_only_zero and i != d and new_is_even){
            continue;
        }
        dp[pos][mod][smaller][only_zero][is_even] = (dp[pos][mod][smaller][only_zero][is_even] % MOD + 
            solve_digit_dp(pos+1, new_mod, new_is_smaller, new_only_zero, new_is_even) % MOD)
             % MOD;
    }

    return dp[pos][mod][smaller][only_zero][is_even] % MOD;
}