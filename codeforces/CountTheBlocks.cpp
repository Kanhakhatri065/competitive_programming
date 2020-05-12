#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int n;
    cin >> n;

    long long int num_of_blocks[n];
    for(int i = 0;i < n;i++) {
        num_of_blocks[i] = 0;
    }

    long long int size = 1;
    for(int i = 1;i <= n;i++) {
        size *= 10;
    }

    for(long long int i = 0;i < size;i++) {
        string temp = "";
        temp = to_string(i);
        
        while(temp.length() != n) {
            temp = '0' + temp;
        }    
        
        int count = 1;

        if(temp.length() > 1) {
            for(int j = 0;j < temp.length() - 1;j++) {
                if(temp[j] == temp[j + 1]) {
                    count++;
                }

                if(temp[j] != temp[j + 1]) {
                    num_of_blocks[count - 1]++;
                    count = 1;
                }

                if((temp[j] == temp[j + 1]) && (j + 1 == temp.length() - 1)) {
                    num_of_blocks[count - 1]++;
                }
                
            }

            if(temp[temp.length() - 2] != temp[temp.length() - 1]) {
                num_of_blocks[0]++;
            }

        } else if(temp.length() == 1) {
            num_of_blocks[0]++;
        }

        
    }

    for(int i = 0;i < n;i++) {
        cout << num_of_blocks[i] << " ";
    }

    cout << endl;

    return 0;
}