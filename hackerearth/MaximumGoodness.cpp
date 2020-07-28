#include <bits/stdc++.h>


using namespace std;

int main(){
    int size;
    cin >> size;

    int arr[size];
    for(int i = 0;i < size;i++){
        cin >> arr[i];
        if(arr[i] == 0){
            arr[i] = -1;
        }
    }

    int current = 0, start = 0, end = 0, max = 0,tempStart = 0, maxLength = 0;

    for(int i = 0;i < size;i++){
        current += arr[i];
        if(current >= max){
            max = current;
            start = tempStart;
            end = i;
        }

        if(current < 0){
            current = 0;
            tempStart = i + 1;
        }

        if((end - start ) >= maxLength){
            maxLength = end - start + 1;
        }
    }

    cout << maxLength << endl;

    return 0;
}