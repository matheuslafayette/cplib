//using dfs
void dfs(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
    answer.push_back(u);
}

void topo_sort_dfs() {
    vis.assign(n, false);
    answer.clear();
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    reverse(answer.begin(), answer.end());
}

//using bfs (khan's algorithm)
void topo_sort_bfs(){
    vector<int> dep(n);
    for(int i = 0; i < n; i++){
        for(int v:adj[i]){
            ++dep[v];
        }
    }

    queue<int> q;
    for(int i = 0; i < n; i++){
        if(dep[i] == 0){
            q.push(i);
        }
    }

    vector<int> answer;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        answer.push_back(u);

        for(int v:adj[u]){
            --dep[v];
            if(dep[v] == 0 && !vis[v]){
                q.push(v);
            }
        }
    }

    if(answer.size() != n){
        cout << "cycle" << endl;
    }
}