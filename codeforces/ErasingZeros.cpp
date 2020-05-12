#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    string str;
    while(testcases--) {
        cin >> str;

        int last_occurence_of_one = -1;
        int count = 0;
        for(int i = 0;i < str.size();i++) {
            if(str[i] == '1') {
                if(last_occurence_of_one == -1) {
                    last_occurence_of_one = i;
                } else {
                    count += (i - last_occurence_of_one - 1);
                    last_occurence_of_one = i;
                }
            }
        }

        cout << count << endl;
    }
    return 0;
}