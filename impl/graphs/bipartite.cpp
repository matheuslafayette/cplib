bool can_bipartite = true;
vector<int> colors(n, -1);

void dfs_bipartite(int source, bool color){
    colors[source] = color;
    for(int next_v:adj[source]){
        if(colors[next_v] == -1){
            dfs(next_v, !color);
        }
        else if(colors[next_v] == color){
            can_bipartite = false;
            break;
        }
    }
}

void bipartite(){
    for(int i = 0; i < n; i++){
        if(colors[i] == -1){
            dfs(i, false);
        }
    }
}