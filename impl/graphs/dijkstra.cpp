void dijkstra(int source){
    dist.assign(n, LLONG_MAX);
    dist[source] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
  
    pq.push({0, source});
  
    while(not pq.empty()){
        auto[distance, v] = pq.top();
        pq.pop();
    
        if(distance > dist[v]){
            continue;
        }
    
        for(auto [next_v, next_dist]:adj[v]){
            if(distance + next_dist < dist[next_v]){
                dist[next_v] = distance + next_dist;
                pq.push({dist[next_v], next_v});
            }
        }
    }
}