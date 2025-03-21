//directed graph

int n;
vector<vector<int>> adj;
vector<char> color; // 0 = unvisited, 1 = visiting, 2 = visited
vector<int> parent;
int cycle_start, cycle_end;

bool dfs_directed(int u) {
    color[u] = 1;
    for (int v : adj[u]) {
        if (color[v] == 0) {
            parent[v] = u;
            if (dfs_directed(v)){
                return true;
            }

        } 
        else if (color[v] == 1) {
            cycle_end = u;
            cycle_start = v;
            return true;
        }
    }
    color[u] = 2;
    return false;
}

void find_cycle_directed() {
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int i = 0; i < n; i++) {
        if (color[i] == 0 && dfs_directed(i)){
            break;
        }
    }

    if (cycle_start == -1) {
        cout << "Acyclic" << endl;
        return;
    }
    vector<int> cycle;
    cycle.push_back(cycle_start);
    for (int v = cycle_end; v != cycle_start; v = parent[v])
        cycle.push_back(v);
    

    cycle.push_back(cycle_start);

    reverse(cycle.begin(), cycle.end());
}

//undirected graph
int n;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs_undirected(int u, int par) {
    vis[u] = true;
    for (int v : adj[u]) {
        if(v == par){
            continue;
        } 
        if (vis[v]) {
            cycle_end = u;
            cycle_start = v;
            return true;
        }
        parent[v] = u;
        if (dfs_undirected(v, parent[v]))
            return true;
    }
    return false;
}

void find_cycle_undirected() {
    vis.assign(n, false);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int i = 0; i < n; i++) {
        if (!vis[i] && dfs(i, parent[i])){
            break;
        }
    }

    if (cycle_start == -1) {
        cout << "Acyclic" << endl;
        return;
    }
    vector<int> cycle;
    cycle.push_back(cycle_start);
    for (int v = cycle_end; v != cycle_start; v = parent[v])
        cycle.push_back(v);
    cycle.push_back(cycle_start);
}