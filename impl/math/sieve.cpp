// find all prime numbers
vector<bool> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}

vector<int> sieveDivisorCount(int N) {
    vector<int> divCount(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i)
            divCount[j]++;
    }
    return divCount;
}

vector<int> getDivisors(int x) {
    vector<int> divs;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            divs.push_back(i);
            if (i != x / i)
                divs.push_back(x / i);
        }
    }
    sort(divs.begin(), divs.end());
    return divs;
}