// =============================
// Fibonacci Twist using Matrices
// =============================

/*
    Definition of the Fibonacci Twist sequence:

    ft(n) = ft(n-1) + ft(n-2) + (n-1)
    with ft(0) = 0 and ft(1) = 1

    First few terms in the sequence:
    n =  0  1  2  3   4   5   6
    ft = 0  1  2  5  10  19  34

    V(n) =
    [ ft(n)   ]  
    [ ft(n-1) ]  
    [ (n-1)   ]  
    [ 1       ]  

    V(n) = T * V(n-1)

    T = [ 1  1  1  -1 ]
        [ 1  0  0   0 ]
        [ 0  0  1   1 ]
        [ 0  0  0   1 ]

    Base: V(1) = [ ft(1) = 1, ft(0) = 0, (n-1) = 2, constant 1 ]
*/

ll fibonacci_twist(ll n, ll mod) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    matrix fib_base = {{1, 1, 1, -1}, 
                       {1, 0, 0,  0}, 
                       {0, 0, 1,  1}, 
                       {0, 0, 0,  1}};

    matrix result = matrix_exponentiation(fib_base, n - 1, mod);

    ll base_case[4] = {1, 0, 2, 1};
    ll answer = 0;

    for (int i = 0; i < 4; i++) {
        answer = (answer + (base_case[i] * result[0][i]) % mod + mod) % mod;
    }

    return answer;
}
