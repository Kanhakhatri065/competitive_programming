#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    cin >> size;

    map<long long int,bool> blocked_coordinate;

    long long int count = 0;

    long long int x_coordinate, y_coordinate, distance;
    for(int i = 0;i < size;i++) {
        cin >> x_coordinate >> y_coordinate >> distance;

        for(long long int j = x_coordinate;j <= x_coordinate + distance;j++) {
            blocked_coordinate[j] = true;
        }


        map<long long int, bool>::iterator itr;

        count = blocked_coordinate.size();
    }

    cout << count << endl;
 
    return 0;
}