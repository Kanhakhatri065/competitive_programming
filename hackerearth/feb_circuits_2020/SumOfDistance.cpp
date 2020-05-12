#include <iostream>
#include <math.h>

using namespace std;

int main(){
    long long int points;
    cin >> points;

    long long int arr[points];
    for(long long int i = 0;i < points;i++){
        cin >> arr[i];
    }

    double output = 0;
    for(long long int i = 0;i < points;i++){
        output += sin(2 * arr[i]);
    }

    printf("%.2lf\n", output);
    return 0;
}