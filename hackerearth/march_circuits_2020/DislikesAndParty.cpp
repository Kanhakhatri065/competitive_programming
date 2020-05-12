#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int people;
    cin >> people;

    long long int dislike[10][10];
    for(int i = 0;i < 10;i++) {
        for(int j = 0;j < 10;j++) {
            cin >> dislike[i][j];
        }
    }

    long long int total_handshakes = (people * (people - 1)) / 2;

    map<long long int, vector<long long int>> m;
    long long int person = 0;
    for(int i = 0;i < 10;i++) {
        person = dislike[i][0];
        for(int j = 1;j < 10;j++) {
            if(person > dislike[i][j]) {
                m[person].push_back(dislike[i][j]);
            } else {
                m[dislike[i][j]].push_back(person);
            }
        }
    }

    map<long long int, vector<long long int>>::iterator itr;

    for(itr = m.begin(); itr != m.end();++itr) {
        vector<long long int> temp = itr->second;

        sort(temp.begin(), temp.end());

        vector<long long int>::iterator ip;

        ip = unique(temp.begin(), temp.end());

        temp.resize(distance(temp.begin(), ip));

        total_handshakes -= temp.size();
    }

    
    cout << total_handshakes << endl;

    return 0;
}