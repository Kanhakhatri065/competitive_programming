#include <iostream>

using namespace std;

int main(){
    int display[] = {6,2,5,5,4,5,6,3,7,6};

    int testcases;
    cin >> testcases;

    int size = 0;
    for(int i = 0;i < testcases;i++){
        cin >> size;
        
        int arr[size];
        for(int j = 0;j < size;j++){
            cin >> arr[j];
        }

        int num_of_bulbs[size];
        int sum = 0;
        int temp = 0;
        int remainder = 0;
        for(int j = 0;j < size;j++){
            sum = 0;
            temp = arr[j];
            remainder = 0;
            while(temp != 0){
                remainder = temp % 10;
                sum = sum + display[remainder];
                temp /= 10;
            }
            num_of_bulbs[j] = sum;
        }

        int minimum_of_bulbs = 0;
        for(int j = 1;j < size;j++){
            if(arr[j] <= arr[j-1]){
                minimum_of_bulbs = j;
            }
        }

        cout << arr[minimum_of_bulbs] << endl;
    }
    return 0;
}