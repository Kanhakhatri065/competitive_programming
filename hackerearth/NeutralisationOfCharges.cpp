#include <iostream>

using namespace std;

int main(){
    long long int size;
    cin >> size;

    char arr[size];
    for(long long int i = 0;i < size;i++){
        cin >> arr[i];
    }

    for(long long int i = 0;i < size - 1;i++){
        if(arr[i] != '0'){
            if(arr[i] == arr[i - 1]){
                arr[i] = arr[i - 1] = '0';
            }
        }
    }

    long long int total = 0;
    string output = "";

    for(long long int i = 0;i < size;i++){
        if(arr[i] != '0'){
            total++;
            output += arr[i];
        }
    }

    cout << total << endl;
    cout << output << endl;

    return 0;
}