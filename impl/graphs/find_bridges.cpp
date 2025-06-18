void IS_BRIDGE(int u, int v);
vector<vector<int>> adj;
int n;

vector<bool> vis;
vector<int> tin, low;
int timer;

void dfs(int u, int p){
    vis[u] = true;
    tin[u] = low[u] = timer++;
    bool parent_skipped = false;
    for(int v:adj[u]){
        if(v == p and !parent_skipped){
            parent_skipped = true;
            continue;
        }
        if(vis[v]){
            low[u] = min(low[u], tin[v]);
        }
        else{
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > tin[u]){
                IS_BRIDGE(u, v);
            }
        }
    }
}

void find_bridges(){
    timer = 0;
    vis.assign(n, false);
    tin.assign(n, -1);
    for(int i = 0; i < n; i++){
        if(not vis[i]){
            dfs(i, -1);
        }
    }
}