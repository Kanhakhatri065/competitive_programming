#include <bits/stdc++.h>
using namespace std;

deque<pair<int, int>> q;
int cnt_added = 0, cnt_removed = 0;

int find_min() {
    return q.front().first;
}

void push_to_queue(int x) {
    while(!q.empty() && q.back().first > x) q.pop_back();
    q.push_back({x, cnt_added});
    cnt_added++;
} 

void remove_element() {
    if(!q.empty() && q.front().second == cnt_removed) {
        cout << "Removed " << q.front().first << endl;
        q.pop_front();
    }

    cnt_removed++;
}

int main() {
    push_to_queue(5);
    push_to_queue(1);
    push_to_queue(3);
    push_to_queue(2);
    
    cout << "Minimum : " << find_min() << endl;
    remove_element();

    return 0;
}
