class DSU{
    private:
        vector<ll> rep;
        vector<ll> size;

    public:
        DSU(ll n){
            size.assign(n, 1);
            rep.resize(n);
            for(int i = 0; i < n; i++){
                rep[i] = i;
            }
        }

        ll find(ll v){
            if(v == rep[v]){
                return v;
            }
            rep[v] = find(rep[v]);
            return rep[v];
        }

        void join(ll u, ll v){
            u = find(u);
            v = find(v);

            if(u == v){
                return;
            }

            if(size[u] < size[v]){
                swap(u, v);
            }

            rep[v] = u;
            size[u] += size[v];
        }
};