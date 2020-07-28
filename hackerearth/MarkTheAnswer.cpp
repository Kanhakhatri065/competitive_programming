#include <iostream>

using namespace std;

int main(){
    int size;
    cin >> size;

    long long int maximum;
    cin >> maximum;

    long long int arr[size];
    for(int i = 0;i < size;i++){
        cin >> arr[i];
    }

    int skip = 0;
    int score = 0;
    for(int i = 0;i < size;i++){
        if(arr[i] <= maximum){
            score++;
        } else {
            skip++;
        }

        if(arr[i] > maximum && skip > 1){
            break;
        }
    }

    cout << score << endl;
    return 0;
}