#include <iostream>

using namespace std;

int main(){
    int size;
    cin >> size;

    int arr[1000001] = {0};
    int x;
    for(int i = 0;i < size;i++){
        cin >> x;
        arr[x]++;
    }

    for(int i = 0;i < 1000001;i++){
        if(arr[i] == 1){
            cout << i << " ";
        }
    }
    return 0;
}