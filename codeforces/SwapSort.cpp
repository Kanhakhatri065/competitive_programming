#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    cin >> size;
    long long int arr[size];
    for(int i = 0;i < size;i++) {
        cin >> arr[i];
    }

    vector<pair<int, int>> store;

    int count = 0, flag = 0;
    long long int current, min;
    int index1, index2;
    for(int i = 0;i < size;i++) {
        current = arr[i];
        index1 = i;
        min = arr[i];
        flag = 0;

        for(int j = i + 1;j < size;j++) {
            if(arr[j] < min) {
                min = arr[j];
                index2 = j;
                flag = 1;
            }
        }

        if(flag == 1) {
            count++;
            store.push_back(make_pair(index1, index2));
            arr[i] = arr[index2];
            arr[index2] = current;
        }
    }

    cout << count << endl;
    if(store.size() > 0) {
        vector<pair<int,int>>::iterator it;
        for(it = store.begin();it != store.end();++it) {
            cout << it->first << " " << it->second << endl;
        }
    }


    return 0;
}