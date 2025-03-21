sort(edges.begin(), edges.end());

ll kruskal(){
    ll total = 0;
    DSU dsu(n);

    for(auto[w, u, v] : edges){
        if(dsu.find(u) != dsu.find(v)){
            dsu.join(u, v);
            total += w;
        }
    }

    return total;
}