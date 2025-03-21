void bfs(int u){
    queue<int> q;
    q.push(u);
    vis[u] = true;
    
    vector<bool> vis(n);
    vector<int> dist(n);
    vector<int> pred(n);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int next_v:adj[v]){
            if(!vis[next_v]){
                vis[next_v] = true;
                q.push(next_v);
                d[next_v] = d[v] + 1;
                pred[next_v] = v;
            }
        }
    }
}