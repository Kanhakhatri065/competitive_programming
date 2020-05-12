#include <iostream>

typedef long long int ll;

using namespace std;

int main() {
    int size1, size2;
    cin >> size1 >> size2;

    string str1[size1];
    for(int i = 0;i < size1;i++) {
        cin >> str1[i];
    }

    string str2[size2];
    for(int i = 0;i < size2;i++) {
        cin >> str2[i];
    }

    int queries;
    cin >> queries;

    ll year;
    while(queries--) {
        cin >> year;

        string outputstr = "";
        if(year % size1 == 0) {
            outputstr += str1[size1 - 1];
        } else {
            outputstr += str1[year % size1 - 1];
        }

        if(year % size2 == 0) {
            outputstr += str2[size2 - 1];
        } else {
            outputstr += str2[year % size2 - 1];
        }

        cout << outputstr << endl;
    }

    return 0;
}