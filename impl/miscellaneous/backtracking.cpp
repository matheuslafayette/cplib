void backtrack(vector<int>& state, vector<int>& choices, vector<bool>& used) {
    if (state.size() == choices.size()) {
        process_solution(state);
        return;
    }
    for (int i = 0; i < choices.size(); i++) {
        if (!used[i] && is_valid(state, choices[i])) {
            used[i] = true;
            state.push_back(choices[i]);

            backtrack(state, choices, used);

            used[i] = false;
            state.pop_back();
        }
    }
}