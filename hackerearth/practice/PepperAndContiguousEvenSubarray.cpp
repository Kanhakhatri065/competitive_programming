#include <bits/stdc++.h>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    int size;
    for(int i = 0;i < testcases;i++){
        cin >> size;

        long long int arr[size];
        for(int j = 0;j < size;j++){
            cin >> arr[j];
        }

        vector<int> store;
        int count = 0;
        for(int j = 0;j < size - 1;j++){
            count = 0;
            for(int k = j + 1;k - size;k++){
                if(arr[k] % 2 == 0){
                    count++;
                } else {
                    break;
                }
            }
            store.push_back(count);
        }

        cout << *max_element(store.begin(),store.end()) << endl;

    }
    return 0;
}