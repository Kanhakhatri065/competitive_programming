#include <iostream>

using namespace std;

int main(){
    int total;
    cin>>total;

    int army[total];
    for(int i = 0;i < total;i++){
        cin>>army[i];
    }

    int lucky = 0, unlucky = 0;
    for(int i = 0;i < total;i++){
        if(army[i] % 2 == 0){
            lucky++;
        }

        if(army[i] % 2 != 0){
            unlucky++;
        }
    }

    if(lucky > unlucky){
        cout << "READY FOR BATTLE" << endl;
    } else {
        cout << "NOT READY" << endl;
    }

    return 0;
}