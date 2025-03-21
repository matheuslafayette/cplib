template <typename T>
class BIT{
private:
    T n;
    vector<T> bit;
    
public:
    BIT(const vector<T>& v){
        n = v.size();
        bit.assign(n+1, 0);

        for(int i = 0; i < n; i++){
            bit[i+1] = v[i];
        }

        for(int i = 1; i <= n; i++){
            int j = i + (i & (-i));
            if(j <= n){
                bit[j] += bit[i];
            }
        }
    }

    void update(int idx, T delta){
        ++idx;
        while(idx <= n){
            bit[idx] += delta;
            idx += idx & (-idx);
        }
    }

    T query(int idx){
        ++idx;
        T sum = 0;
        while(idx > 0){
            sum += bit[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }

    T range_query(int l, int r){
        return (l == 0) ? query(r) : query(r) - query(l - 1);
    }                                                                                                                                                                                           
};