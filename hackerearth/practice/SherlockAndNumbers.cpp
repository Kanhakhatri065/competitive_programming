#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    long long int N, K, P;
    for(int i = 0;i < testcases;i++) {
        cin >> N >> K >> P;

        map<long long int,int> arr;
        for(int j = 1;j <= N;j++) {
            arr[j]++;
        }

        vector<long long int> store;


        long long int temp;
        for(int j = 0;j < K;j++) {
            cin >> temp;
            store.push_back(temp);
        }

        for(int j = 0;j < K;j++) {
           arr.erase(store[j]);
        }

        map<long long int, int>::iterator it;
        for(it = arr.begin();it != arr.end();++it) {
            P--;
            if(P == 0) {
                cout << it->first << endl;
                break;
            }
        }

        if(P > 0) {
            cout << "-1" << endl;
        }
    }
    return 0;
}