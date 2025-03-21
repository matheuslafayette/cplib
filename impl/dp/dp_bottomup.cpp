int coinChangeBottomUp(const vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INF);
    dp[0] = 0;
    for (int a = 1; a <= amount; a++) {
        for (int coin : coins) {
            if (a - coin >= 0)
                dp[a] = min(dp[a], dp[a - coin] + 1);
        }
    }
    return dp[amount] == INF ? -1 : dp[amount];
}