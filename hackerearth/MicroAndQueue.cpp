#include <bits/stdc++.h>

using namespace std;

int main() {
    int operations;
    cin >> operations;

    queue<int> q;

    char type;
    int number;
    while(operations--) {
        cin >> type;
        if(type == 'E') {
            cin >> number;
            q.push(number);
            cout << q.size() << endl;
        } else {
            if(!q.empty()) {
                int temp = q.front();
                q.pop();

                cout << temp << " " << q.size() << endl;
            } else {
                cout << "-1 " << q.size() << endl;
            }
        }
    }

    return 0;
}