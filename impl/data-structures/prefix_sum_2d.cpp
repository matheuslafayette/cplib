// 1-based indexing (entry vector v should be 1-based as well)
vector<vector<ll>> ps(n+1, vector<ll>(n+1));
for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
        ps[i][j] = v[i][j] + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
    }
}

auto query = [&](int xi, int yi, int xf, int yf){
    return ps[xf][yf] - ps[xf][yi-1] - ps[xi-1][yf] + ps[xi-1][yi-1];
};