#include <bits/stdc++.h>

using namespace std;

int main(){
    int size, query;
    cin >> size >> query;

    int arr[size];
    for(int i = 0;i < size;i++){
        cin >> arr[i];
    }

    for(int i = 0;i < query;i++){
        int type;
        cin >> type;
        if(type == 1){
            int x;
            cin >> x;
            if(arr[x-1] == 1){
                arr[x-1] = 0;
            } else if(arr[x-1] == 0){
                arr[x-1] = 1;
            }
        } else if(type == 0){
            int l,r;
            cin >> l >> r;

            if(arr[r-1] == 1){
                cout << "ODD" << endl;
            } else if(arr[r-1] == 0){
                cout << "EVEN" << endl;
            }
        }
    }
    return 0;
}