void dfs(int u){
    vis[u] = true;
    for(int v:adj[u]){
        dfs(v);
    }
}