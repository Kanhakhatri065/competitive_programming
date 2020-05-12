#include <iostream>

using namespace std;

int main() {
    int size;
    cin >> size;

    int total = 0;
    int percent;
    for(int i = 0;i < size;i++) {
        cin >> percent;
        total += percent;
    }

    double concentration = ((double) total) / (size * 100);

    printf("%.12lf\n", (concentration * 100)); 

    return 0;
}