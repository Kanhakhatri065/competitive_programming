#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int k;
    cin >> k;

    int arr[n];
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }

    int counter = 2;
    while(1){
        int not_possible = 0;
        for(int i = 0;i <= n - counter;i++){
            int temparr[counter];            
            for(int j = 0;j < counter;j++){
                temparr[j] = arr[i + j];
            }

            int size = sizeof(temparr) / sizeof(temparr[0]);
            sort(temparr,temparr + size);
            
            int last_number = temparr[counter - 1];
            int increment = 0;
            for(int k = 0;k < counter;k++){
                int add = last_number - temparr[k];
                temparr[k] += add;
                increment += add;
            }
            
            if(increment > k){
                not_possible++;
            }
        }

        if(not_possible > 0){
            break;
        }
        counter++;
    }

    cout << counter << endl;

    return 0;
}