template <typename T>
class SegTree{
 
private:
    int n;
    vector<T> tree;
 
    T combine(T a, T b){
        return (a + b);
    }
 
    T identity = 0;
 
    void build(const vector<T>& v, int node, int start, int end){
        if(start == end){
            tree[node] = v[start];
            return;
        }
        int mid = (start + end) / 2;
        build(v, 2*node, start, mid);
        build(v, 2*node+1, mid+1, end);
        tree[node] = combine(tree[2*node], tree[2*node+1]);
    }
 
    T query(int node, int start, int end, int l, int r){
        if(r < start or l > end){
            return identity;
        }
        if(l <= start and end <= r){
            return tree[node];
        }
        int mid = (start + end) / 2;
        T left_query = query(2*node, start, mid, l, r);
        T right_query = query(2*node+1, mid+1, end, l, r);
        return combine(left_query, right_query);
    }
 
    void update(int node, int start, int end, int idx, T val){
        if(start == end){
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if(idx <= mid){
            update(2*node, start, mid, idx, val);
        }
        else{
            update(2*node+1, mid+1, end, idx, val);
        }
        tree[node] = combine(tree[2*node], tree[2*node+1]);
    }
 
public:
    SegTree(const vector<T>& v){
        n = v.size();
        tree.resize(4*n);
        build(v, 1, 0, n-1);
    }
 
    T query(int l, int r){
        return query(1, 0, n-1, l, r);
    }
 
    void update(int idx, T val){
        update(1, 0, n-1, idx, val);
    }
};
 