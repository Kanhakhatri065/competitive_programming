#include <bits/stdc++.h>
using namespace std;

stack<pair<int, int>> st;

void push_to_stack(int x) {
    int new_min = st.empty() ? x : min(x, st.top().second);
    st.push({x, new_min});
}

int pop_from_stack() {
    int x = st.top().first;
    st.pop();
    return x;
}

int find_min() {
    if(st.empty()) return -1;
    return st.top().second;
}

int main() {
    push_to_stack(5);
    push_to_stack(4);
    push_to_stack(2);
    push_to_stack(1);
    push_to_stack(3);

    while(!st.empty()) {
        cout << "Min : " << find_min() << " top : " << pop_from_stack() << endl;
    }

    return 0;
}
