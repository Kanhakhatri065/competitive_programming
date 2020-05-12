#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    int queens;
    for(int i = 0;i < testcases;i++) {
        cin >> queens;

        vector<int> num_of_kingsdoms_proposed;
        vector<vector<int>> kingdoms;
        
        int temp1 = 0;
        int temp2 = 0;
        for(int j = 0;j < queens;j++) {
            cin >> temp1;
            num_of_kingsdoms_proposed.push_back(temp1);

            vector<int> temp;
            for(int k = 0;k < temp2;k++) {
                cin >> temp2;
                temp.push_back(temp2);
            }

            kingdoms.push_back(temp);
        }

        vector<int> marry[queens];
        for(int j = 0;j < queens;j++) {
            
        }
    }

    return 0;
}