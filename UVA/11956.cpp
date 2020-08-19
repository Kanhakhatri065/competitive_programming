#include <bits/stdc++.h>

using namespace std;

vector<int> output(110);

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int index, cases;
    string instruction;
    char option;
    
    cin >> cases;

    for(int cc = 1;cc <= cases;cc++) {
        cin >> instruction;
        fill(output.begin(), output.end(), 0);
        index = 0;

        for(int i = 0;i < instruction.size();i++) {
            option = instruction[i];

            if(option == '>') {
                index++;

                if(index >= 100) {
                    index = 0;
                }
            } else if(option == '<') {
                index--;
                if(index <= -1) {
                    index = 99;
                }
            } else if(option == '+') {
                output[index]++;

                if(output[index] > 255) {
                    output[index] = 0;
                }
            } else if(option == '-') {
                output[index]--;

                if(output[index] < 0) {
                    output[index] = 255;
                }
            } else if(option == '.') {
                continue;
            }
        }

        cout << "Case " << cc << ": ";
        for(int i = 0;i < 100;i++) {
            if(i < 99) {
                printf("%02X ", output[i]);
            } else {
                printf("%02X\n", output[i]);
            }
        }
    }

    return 0;
}