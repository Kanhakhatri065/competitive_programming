#include <bits/stdc++.h>

using namespace std;

int main() {
    map<string, string> m;
    m["purple"] = "Power";
    m["green"] = "Time";
    m["blue"] = "Space";
    m["orange"] = "Soul";
    m["red"] =  "Reality";
    m["yellow"] = "Mind";

    int n;
    cin >> n;
    string temp;
    for(int i = 0;i < n;i++) {
        cin >> temp;
        m.erase(temp);
    }

    if(m.empty()) {
        cout << "0" << endl;
    } else {
        cout << m.size() << endl;
        map<string,string>::iterator it;
        for(it = m.begin();it != m.end();++it) {
            cout << it->second << endl;
        }
    }

    return 0;
}