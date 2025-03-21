if (!vis[u]) {
    cout << "No path!";
    return;
} 
vector<int> path;
for (int v = u; v != -1; v = p[v])
    path.push_back(v);
    
reverse(path.begin(), path.end());