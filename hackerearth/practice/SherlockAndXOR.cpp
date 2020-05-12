#include <iostream>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;
    for(int i = 0;i < testcases;i++){
        int size;
        cin >> size;

        long long int arr[size];
        for(int j = 0;j < size;j++){
            cin >> arr[j];
        }

        int even = 0,odd = 0;
        for(int j = 0;j < size;j++){
            if(arr[j] % 2 == 0){
                even++;
            } else {
                odd++;
            }
        }

        int total = even * odd;
        cout << total << endl;
    }

    return 0;
}