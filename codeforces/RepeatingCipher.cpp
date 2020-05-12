#include <iostream>

using namespace std;

int main() {
    int size;
    cin >> size;

    string str;
    cin >> str;

    string outputstr = "";

    int k = 0;
    for(int i = 0;i < size;i += k) {
        outputstr += str[i];
        k++;
    }

    cout << outputstr << endl;
    
    return 0;
}