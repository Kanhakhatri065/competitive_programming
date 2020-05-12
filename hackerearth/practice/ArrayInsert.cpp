#include <iostream>

using namespace std;

int main(){
    int size, queries;
    cin >> size >> queries;

    int arr[size];
    for(int i = 0;i < size;i++){
        cin >> arr[i];
    }

    for(int i = 0;i < queries;i++){
        int type, x, y;
        cin >> type >> x >> y;

        if(type == 1){
            arr[x] = y;
        } else {
            int sum = 0;
            for(int j = x;j <= y;j++){
                sum += arr[j];
            }

            cout << sum << endl;
        }
    }
    return 0;
}