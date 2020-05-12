#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int testcases;
    cin >> testcases;

    for(int i = 0;i < testcases;i++){
        int amount;
        cin >> amount;

        int totalnotes = 0;
        while(amount != 0){
            if(amount / 100 != 0){
                totalnotes++;
                amount = amount - 100;
            } else if(amount / 50 != 0){
                totalnotes++;
                amount = amount - 50;
            } else if(amount / 10 != 0){
                totalnotes++;
                amount = amount - 10;
            } else if(amount / 5 != 0){
                totalnotes++;
                amount = amount - 5;
            } else if(amount / 2 != 0){
                totalnotes++;
                amount = amount - 2;
            } else {
                totalnotes++;
                amount--;
            }
        }

        cout << totalnotes << endl;
    }

    return 0;
}
