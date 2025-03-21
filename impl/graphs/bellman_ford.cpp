struct Edge {
    int a, b, cost;
};

void bellman_ford(int u)
{
    vector<int> dist(n, INF);
    dist[u] = 0;
    for (int i = 0; i < n - 1; ++i)
        for (Edge e : edges)
            if (dist[e.a] < INF)
                dist[e.b] = min(dist[e.b], dist[e.a] + e.cost);
}