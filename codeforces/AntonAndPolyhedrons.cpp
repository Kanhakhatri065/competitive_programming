#include <iostream>

using namespace std;

int faces(string str) {
    if(str == "Tetrahedron") {
        return 4;
    } else if(str == "Cube") {
        return 6;
    } else if(str == "Octahedron" ) {
        return 8;
    } else if(str == "Dodecahedron") {
        return 12;
    } else if(str == "Icosahedron") {
        return 20;
    }

    return 0;
}

int main() {
    long long int number;
    cin >> number;
    
    long long int count = 0;
    string str;
    while(number--) {
        cin >> str;
        count += faces(str);
    }

    cout << count << endl;

    return 0;
}