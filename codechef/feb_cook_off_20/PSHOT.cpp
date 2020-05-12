#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    int shots = 0;
    for(int i = 0;i < testcases;i++){
        cin >> shots;

        string shootout;
        cin >> shootout;

        int a_goals = 0;
        int b_goals = 0;
        long long int counter = 0;
        for(long long int j = 0;j < shootout.length();j++){
            if(abs(a_goals - b_goals) > 1 && j > shots){
                break;
            }

            if(j % 2 == 0){
                if(shootout[j] == '1'){
                    a_goals++;
                }
            }

            if(j % 2 != 0){
                if(shootout[j] == '1'){
                    b_goals++;
                }
            }

            counter++;
        }

        cout << counter << endl;

    }

    return 0;
}