#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int size;
    cin >> size;

    int vaccine_count[size];
    for(int i = 0;i < size;i++) {
        cin >> vaccine_count[i];
    }

    int patient_count[size];
    for(int i = 0;i < size;i++) {
        cin >> patient_count[i];
    }

    sort(vaccine_count, vaccine_count + size);
    sort(patient_count, patient_count + size);

    int flag = 0;
    for(int i = size - 1;i >= 0;i--) {
        if(vaccine_count[i] <= patient_count[i]) {
            flag = 1;
            break;
        }
    }

    if(flag == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}