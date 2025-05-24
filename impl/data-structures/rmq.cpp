class RMQ {
private:
    int n, K;
    std::vector<int> lg;
    std::vector<std::vector<int>> st;

public:
    RMQ(const std::vector<int>& a) {
        n = int(a.size());
        K = std::floor(std::log2(n));

        lg.assign(n+1, 0);
        for (int i = 2; i <= n; i++)
            lg[i] = lg[i/2] + 1;

        st.assign(K+1, std::vector<int>(n));

        for (int i = 0; i < n; i++)
            st[0][i] = a[i];

        for (int k = 1; k <= K; k++) {
            int len = 1 << k;
            for (int i = 0; i + len <= n; i++) {
                st[k][i] = std::min(
                    st[k-1][i],
                    st[k-1][i + (len >> 1)]
                );
            }
        }
    }

    int query(int L, int R) const {
        int len = R - L + 1;
        int k = lg[len];
        int span = 1 << k;
        return std::min(
            st[k][L],
            st[k][R - span + 1]
        );
    }
};