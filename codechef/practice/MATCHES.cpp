#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int matchesPerNumber[] = {6,2,5,5,4,5,6,3,7,6};
     
    int testcases;
    cin >> testcases;

    for(int i = 1;i <= testcases;i++){
        int a,b;
        cin >> a >> b;
        int sum = a + b;

        int totalmatches = 0;
        while(sum != 0){
            int digit = sum % 10;
            totalmatches = totalmatches + matchesPerNumber[digit];
            sum = sum / 10;
        }

        cout << totalmatches << endl;
    }

    return 0;
}