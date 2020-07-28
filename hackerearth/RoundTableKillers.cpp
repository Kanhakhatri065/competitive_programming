#include <iostream>

using namespace std;

int main(){
    int total, special, initial;
    cin >> total >> special >> initial;

    int arr[total + 1];
    for(int i = 0;i <=total;i++){
        arr[i] = i;
    }

    arr[0] = -1;
    int flag = 1;
    int kill = 0;
    int count = 0;
    while(flag != 0){
        if(initial % special != 0){
            kill = initial + (initial % special);
            if(kill > total){
                kill = kill%total;
            } 
        } else {
            kill = 0;
        }
                
        arr[kill] = -1;
        if(kill != 0){
            count++;
        }

        initial = initial + kill + 1;
        if(initial > total){
            initial = initial % total;
        }
        
        if(count == total){
            flag = 0;
        }
    }

    cout << initial << endl;

    return 0;
}