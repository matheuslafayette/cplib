int lcsTopDownHelper(const string &s1, const string &s2, int i, int j, vector<vector<int>> &memo) {
    if (i == s1.size() || j == s2.size())
        return 0;
    if (memo[i][j] != -1)
        return memo[i][j];
    if (s1[i] == s2[j])
        memo[i][j] = 1 + lcsTopDownHelper(s1, s2, i + 1, j + 1, memo);
    else
        memo[i][j] = max(lcsTopDownHelper(s1, s2, i + 1, j, memo), lcsTopDownHelper(s1, s2, i, j + 1, memo));
    return memo[i][j];
}
 
int lcsTopDown(const string &s1, const string &s2) {
    vector<vector<int>> memo(s1.size(), vector<int>(s2.size(), -1));
    return lcsTopDownHelper(s1, s2, 0, 0, memo);
}