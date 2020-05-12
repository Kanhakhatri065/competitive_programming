#include <iostream>

using namespace std;

int main() {
    unsigned long long int n, m, a;
    cin >> n >> m >> a;

    long long int count = 0;
    
    long long int height = n / a;
    
    n -= height * a;
    
    if(n > 0) {
        height++;
    }

    long long int breath = m / a;
    
    m -= breath * a;
    
    if(m > 0) {
        breath++;
    }

    count = height * breath;

    cout << count << endl;

    return 0;
}