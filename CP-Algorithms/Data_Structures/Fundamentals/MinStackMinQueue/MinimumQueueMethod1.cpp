#include <bits/stdc++.h>
using namespace std;

deque<int> q;

int find_min() {
    return q.front();
}

void push_to_queue(int x) {
    while(!q.empty() && q.back() > x) q.pop_back();
    q.push_back(x);
}

void remove_element(int x) {
    if(!q.empty() && q.front() == x) q.pop_front();
}

int main() {
    push_to_queue(5);
    push_to_queue(1);
    push_to_queue(3);
    push_to_queue(2);

    cout << "Minimum : " << find_min() << endl;
    return 0;
}
