#include <iostream>

using namespace std;

int main() {
    long long int size;
    cin >> size;

    string arr[size];
    for(long long int i = 0;i < size;i++) {
        cin >> arr[i];
    }

    long long int count = 1;
    for(long long int i = 0;i < size - 1;i++) {
        if(arr[i] != arr[i + 1]) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}