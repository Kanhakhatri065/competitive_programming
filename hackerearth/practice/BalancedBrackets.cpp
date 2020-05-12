#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    string str;
    while(testcases--) {
        cin >> str;

        stack<char> s;
        for(int i = 0;i < str.size();i++) {
            if(str[i] == '(' || str[i] == '[' || str[i] == '{') {
                s.push(str[i]);
                continue;
            }

            if(!s.empty()) {
                if((s.top() == '(' && str[i] == ')') || (s.top() == '[' && str[i] == ']') || (s.top() == '{' && str[i] == '}')) {
                    s.pop();
                }  
            }
        }

        if(s.empty()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}