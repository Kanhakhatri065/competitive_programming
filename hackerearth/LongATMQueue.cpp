#include <bits/stdc++.h>

using namespace std;

int main(){
    int size;
    cin >> size;

    int arr[size];
    for(int i = 0;i < size;i++){
        cin >> arr[i];
    }

    int total = 0;
    for(int i = 0;i < size-1;i++){
        if(i == 0){
            total++;
        }

        if((i != 0) && (arr[i] > arr[i+1])){
            total++;
        }
    }
    
    cout << total << endl;
    
    return 0;
}