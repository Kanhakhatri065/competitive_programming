#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    for(int i = 0;i < testcases;i++){
        int size, perChange;
        cin >> size >> perChange;

        long long int arr1[size];
        for(int j = 0;j < size;j++){
            cin >> arr1[j];
        }

        long long int arr2[size];
        for(int j = 0;j < size;j++){
            cin >> arr2[j];
        }

        sort(arr2, arr2 + size);

        int change = arr2[size - 1] + 1;
        int totalTime = 0;
        for(int j = 0;j < size;j++){
            if(arr1[j] < change){
                totalTime += (change - arr1[j]) * perChange;
            }
        }

        cout << totalTime << endl;
    }
    return 0;
}