#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    int num_of_boys, num_of_girls;
    for(int i = 0;i < testcases;i++) {
        cin >> num_of_boys >> num_of_girls;

        if(num_of_boys > num_of_girls) {
            cout << "NO" << endl;
        } else {
            int boys[num_of_boys];
            for(int j = 0;j < num_of_boys;j++) {
                cin >> boys[j];
            }

            int girls[num_of_girls];
            for(int j = 0;j < num_of_girls;j++) {
                cin >> girls[j];
            }

            sort(boys, boys + num_of_boys);
            sort(girls, girls + num_of_girls);

            int flag = 0;
            for(int j = 0;j < num_of_boys;j++) {
                if(boys[j] <= girls[j]) {
                    flag = 1;
                    break;
                }
            }

            if(flag == 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}