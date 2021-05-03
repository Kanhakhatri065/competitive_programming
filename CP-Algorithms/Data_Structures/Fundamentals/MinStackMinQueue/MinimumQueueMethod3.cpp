#include <bits/stdc++.h>
using namespace std;

stack<pair<int, int>> s1, s2;

int find_min() {
    int mn;
    if(s1.empty() || s2.empty()) {
        mn = s1.empty() ? s2.top().second : s1.top().second;
    } else {
        mn = min(s1.top().second, s2.top().second);
    }

    return mn;
}

void enqueue(int x) {
    int mn = s1.empty() ? x : min(x, s1.top().second);
    s1.push({x, mn});
}

void dequeue() {
    if(s2.empty()) {
        while(!s1.empty()) {
            int element = s1.top().first;
            s1.pop();
            int mn = s2.empty() ? element : min(element, s2.top().second);
            s2.push({element, mn});
        }
    }

    int remove_element = s2.top().first;
    s2.pop();

    cout << "Removed : " << remove_element << endl;
}

int main() {
    enqueue(5);
    enqueue(3);
    enqueue(2);
    enqueue(4);
    
    cout << "Minimum : " << find_min() << endl;
    dequeue();
    dequeue();
    dequeue();
    return 0;
}
