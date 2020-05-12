#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int testcases;
    cin>>testcases;

    for(int i = 1;i<=testcases;i++){
        int number;
        cin>>number;
        double numRoot = sqrt(number);
        int result = (int)numRoot;
        cout << result << endl;
    }
    return 0;
}