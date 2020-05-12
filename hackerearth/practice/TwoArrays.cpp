#include <iostream>

using namespace std;

int main(){
    int size;
    cin >> size;

    long long int arr1[size];
    for(int i= 0;i < size;i++){
        cin >> arr1[i];
    }

    long long int arr2[size];
    for(int i = 0;i < size;i++){
        cin >> arr2[i];
    }

    int negativeInFirst = 0;
    int negativeInSecond = 0;
    int sumFirst = 0;
    int sumSecond = 0;
    for(int i = 0;i < size;i++){
        sumFirst += arr1[i];
        sumSecond += arr2[i];

        if(arr1[i] == -1){
            negativeInFirst++;
        }

        if(arr2[i] == -1){
            negativeInSecond++;
        }
    }

    if(negativeInFirst == 1 && negativeInSecond == 1){
        if(sumFirst == sumSecond){
            cout << "Infinite" << endl;
        }        
    }

    if(negativeInFirst + negativeInSecond == 1){
        if(negativeInFirst == 1 && sumFirst <= sumSecond){
            cout << "1" << endl;
        } else if(negativeInSecond == 1 && sumSecond <= sumFirst){
            cout << "1" << endl;
        }   else {
            cout << "0" << endl;
        }
    }

    if(negativeInFirst + negativeInSecond == 2){
        int number = abs(sumFirst - sumSecond) + negativeInFirst + negativeInSecond;

        int output = number + 1;

        cout << output << endl;
    }

    return 0;
}