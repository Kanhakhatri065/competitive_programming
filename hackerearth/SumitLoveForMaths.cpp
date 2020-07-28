#include <iostream>
#include <math.h>
using namespace std;

int gcd(int a, int b){
    if(a > b){
        return gcd(a-b,b);
    } else if(a < b){
        return gcd(a,b-a);
    } else {
        return a;
    }
}

int lcm(int a, int b){
    return (a * b) / gcd(a,b);
}

int main(){
    int testcases;
    cin >> testcases;

    long long int number = 0;
    int a, b, c;
    for(int i = 0;i < testcases;i++){
        cin >> number >> a >> b >> c;

        long long int total = number/a + number/b + number/c;
        total = total - number/lcm(a,b) - number/lcm(b,c) - number/lcm(a,c) + number/lcm(a,lcm(b,c));

        cout << total << endl;
    }
    return 0;
}