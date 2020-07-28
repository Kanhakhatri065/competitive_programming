#include <bits/stdc++.h>

using namespace std;

int  main() {
    int testcases;
    cin >> testcases;

    int size;
    for(int i = 0;i < testcases;i++) {
        cin >> size;
        vector<long long int> arr;
        long long int temp;
        for(int j = 0;j < size;j++) {
            cin >> temp;
            arr.push_back(temp);
        }

        for(int p = 0;p < size - 2;p++) {
            vector<map<long long int, int>> storeSubArrays;
            for(int j = 0;j < size;j++) {
                for(int k = j;k < size;k++) {
                    map<long long int,int>temp;
                    for(int l = j;l <= k;l++) {
                        temp.insert(pair<long long int, int>(arr[l], l));
                    }

                    if(temp.size() > 2 && temp.size() % 2 != 0) {
                        storeSubArrays.push_back(temp);
                    }
                }
            }

            map<long long int, int>m;
            for(int j = 0;j < storeSubArrays.size();j++) {
                int middle = storeSubArrays[j].size() / 2;
                
                int count = 0;
                for(auto& x: storeSubArrays[j]) {
                    if(count == middle) {
                        long long int median = x.first;
                        int indexOfMedian = x.second;
                        m.insert(pair<long long int,int>(median, indexOfMedian));
                        break;
                    }
                    count++;
                }
            }

            int indexOfMinMedian = m.begin()->second;

            cout << indexOfMinMedian << " ";

            arr.erase(arr.begin() + indexOfMinMedian);
        } 

        long long int sum = 0;
        for(int j = 0;j < arr.size();j++) {
            sum += arr[j];
        }

        cout << sum << endl;
    }
    return 0;
}