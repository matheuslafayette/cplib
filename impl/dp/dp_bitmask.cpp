// setCoverDP:
// What it does: Computes the minimum cost to cover all required properties.
// Each item covers a set of properties (represented as a bitmask) at a certain cost.
// When to use: Use this function when you face a set cover problem where you need to select
// a subset of items to cover all properties with the minimum total cost.

struct Item {
    int mask, cost;
};
 
int setCoverDP(const vector<Item>& items, int m) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(1 << m, INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << m); mask++) {
            dp[i + 1][mask] = min(dp[i + 1][mask], dp[i][mask]);
            int new_mask = mask | items[i].mask;
            if (dp[i][mask] != INF)
                dp[i + 1][new_mask] = min(dp[i + 1][new_mask], dp[i][mask] + items[i].cost);
        }
    }
    return dp[n][(1 << m) - 1];
}
 
// tspDP:
// What it does: Computes the minimum cost to visit all vertices in a complete graph starting from vertex 0.
// It uses a bitmask DP approach to solve the Traveling Salesman Problem (TSP) or similar path-cover problems.
// When to use: Use this function when you need to determine the shortest path that visits every vertex
// exactly once in problems like TSP.
int tspDP(const vector<vector<int>>& graph) {
    int n = graph.size(), N = 1 << n;
    vector<vector<int>> dp(N, vector<int>(n, INF));
    dp[1][0] = 0; // start at vertex 0, mask = 1<<0
    for (int mask = 0; mask < N; mask++) {
        if (!(mask & 1)) continue; // ensure starting vertex is visited
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;
            for (int v = 0; v < n; v++) {
                if (mask & (1 << v)) continue;
                dp[mask | (1 << v)][v] = min(dp[mask | (1 << v)][v], dp[mask][u] + graph[u][v]);
            }
        }
    }
    int result = INF;
    for (int u = 0; u < n; u++) {
        result = min(result, dp[N - 1][u]);
    }
    return result;
}