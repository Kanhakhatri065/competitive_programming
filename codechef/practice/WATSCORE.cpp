#include <iostream>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    for(int i = 0;i < testcases;i++){
        int size = 11;
        int arr[size];
        
        for(int j = 0;j < size;j++){
            arr[j] = 0;
        }

        int numOfSubmission;
        cin >> numOfSubmission;

        for(int j = 0;j < numOfSubmission;j++){
            int question,marks;
            cin >> question >> marks;

            if(arr[question - 1] < marks){
                arr[question - 1] = marks;
            }
        }

        int sum = 0;
        for(int j = 0;j < size - 3;j++){
            sum = sum + arr[j];
        }

        cout << sum << endl;
    }

    return 0;
}