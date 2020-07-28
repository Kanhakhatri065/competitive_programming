#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    int size;
    for(int i = 0;i < testcases;i++){
        cin >> size;

        int arr[size];
        for(int j = 0;j < size;j++){
            cin >> arr[j];
        }

        int prefixxor[size];
        int temp = 0;
        for(int j = 0;j < size;j++){
            temp = arr[0];
            if(j > 0) {
                for(int k = 1;k <= j;k++){
                    temp = temp ^ arr[k];
                }
            }
            prefixxor[j] = temp;
        }

        sort(prefixxor, prefixxor + size);

        cout << prefixxor[size - 1] << endl;
    }

    return 0;
}
