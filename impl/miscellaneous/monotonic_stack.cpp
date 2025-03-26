void monotonic_stack(){
    vector<int> v(N);
    vector<int> left(N);
    vector<int> right(N);

    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    stack<ii> stack_left;
    stack<ii> stack_right;

    stack_left.push({v[0], 0});
    stack_right.push({v[N-1], N-1});
    left[0] = -1;
    right[N-1] = -1;

    for(int i = 1; i < N; i++){
        while(not stack_left.empty() and v[i] <= stack_left.top().first){
            stack_left.pop();
        }
        left[i] = stack_left.empty() ? -1 : stack_left.top().second;
        stack_left.push({v[i], i});

        int j = N-1-i;
        while(not stack_right.empty() and v[j] <= stack_right.top().first){
            stack_right.pop();
        }
        right[j] = stack_right.empty() ? -1 : stack_right.top().second;
        stack_right.push({v[j], j});
    }
}