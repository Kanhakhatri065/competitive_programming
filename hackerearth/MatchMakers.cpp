#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    int testcases;
    cin >> testcases;

    int size;
    for(int i = 0;i < testcases;i++) {
        cin >> size;

        int girls[size];
        for(int j = 0;j < size;j++) {
            cin >> girls[j];
        }

        int boys[size];
        for(int j = 0;j < size;j++) {
            cin >> boys[j];
        }

        sort(girls, girls + size);
        sort(boys, boys + size, greater<int>());

        int count = 0;
        for(int j = 0;j < size;j++) {
            if((girls[j] % boys[j] == 0) || (boys[j] % girls[j] == 0)) {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
