#include <bits/stdc++.h>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    int num_of_cars = 0;

    int total = 1;
    for(int i = 0;i < testcases;i++){
        cin >> num_of_cars;

        int arr[num_of_cars];
        for(int j = 0;j < num_of_cars;j++){
            cin >> arr[j];
        }
        
        total = 1;
        for(int j = 0;j < num_of_cars - 1;j++){
            if(arr[j] >= arr[j+1]){
                total++;
            } else {
                arr[j+1] = arr[j];
            }
        }

        cout << total << endl;
    }
    return 0;
}