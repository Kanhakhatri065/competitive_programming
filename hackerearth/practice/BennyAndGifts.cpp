#include <bits/stdc++.h>

using namespace std;

int main() {
    string input;
    cin >> input;

    long long int x_coordinate = 0;
    long long int y_coordinate = 0;

    map<pair<long long int, long long int>, long long int> m;
    pair<long long int, long long int> temp;
    temp = make_pair(x_coordinate, y_coordinate);
    m[temp]++;
    for(int i = 0;i < input.length();i++) {
        if(input[i] == 'L') {
            y_coordinate--;
        } else if(input[i] == 'R') {
            y_coordinate++;
        } else if(input[i] == 'U') {
            x_coordinate--;
        } else if(input[i] == 'D') {
            x_coordinate++;
        }


        temp = make_pair(x_coordinate, y_coordinate);
        m[temp]++;
    }

    long long int count = 0;
    map<pair<long long int, long long int>, long long int>::iterator it;
    long long int temp_x, temp_y;
    for(it = m.begin();it != m.end();++it) {
        if(it-> second > 1) {
            count += (it->second - 1);
        }
    }

    cout << count << endl;

    return 0;
}