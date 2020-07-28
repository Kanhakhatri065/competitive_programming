#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    int size;
    for(int i = 0;i < testcases;i++) {
        cin >> size;

        vector<long long int> arr;
        vector<long long int> sorted_arr;
        
        long long int temp;
        for(int j = 0;j < size;j++) {
            cin >> temp;
            arr.push_back(temp);
            sorted_arr.push_back(temp);
        }

        sort(sorted_arr.begin(), sorted_arr.end());

        int count = 0;
        vector<long long int>::iterator itr;
        for(int j = 0;j < size;j++) {
            count = 0;
            itr = sorted_arr.begin();
            for(auto it = sorted_arr.begin();it != sorted_arr.end();++it) {
                if(*it == arr[j]) {
                    sorted_arr.erase(itr);
                    cout << count << " ";
                    break;
                }
                count++;
                itr++;
            }
        }
        cout << endl;
    }

    return 0;
}