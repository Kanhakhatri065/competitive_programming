#include <iostream>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    for(int i = 0;i < testcases;i++){
        int size;
        cin >> size;
        
        char arr[size];
        for(int j = 0;j < size;j++){
            cin >> arr[j];
        }

        int count = 0;
        for(int j = 0;j < size;j++){
            if(arr[j] >= 48 && arr[j] <= 57){
                if(j > 0){
                    if(arr[j - 1] >= 48 && arr[j - 1] <= 57){
                        continue;
                    } else {
                        count++;
                    }
                } else {
                    count++;
                }
            }

        }
        cout << count << endl;
    }
    return 0;
}