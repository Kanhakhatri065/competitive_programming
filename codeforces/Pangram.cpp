#include <bits/stdc++.h>

using namespace std;



int main() {
    int size;
    cin >> size;

    string sentence;
    cin >> sentence;
    
    int alphabets[26];
    for(int i = 0;i < 26;i++) {
        alphabets[i] = 0;
    }

    char temp;
    int temp_num;
    for(int i = 0;i < size;i++) {
        temp = sentence[i];
        if(temp >= 65 && temp <= 90) {
            temp_num = temp - 65;
            alphabets[temp_num]++;
        } else if(temp >= 97 && temp <= 122) {
            temp_num = temp - 97;
            alphabets[temp_num]++;
        }
    }

    int count = 0;
    for(int i = 0;i < 26;i++) {
        if(alphabets[i] > 0) {
            count++;
        }
    }

    if(count == 26) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}