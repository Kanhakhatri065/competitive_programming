#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    string str;
    while(testcases--) {
        cin >> str;

        int mid = 0;
        string left = "";
        string right = "";
        if(str.size() % 2 == 0) {
            mid = (str.size() / 2) - 1;
            
            for(int i = 0;i <= mid;i++) {
                left += str[i];
            }

            for(int i = mid + 1;i < str.size();i++) {
                right += str[i];
            }
        } else {
            mid = str.size() / 2;

            for(int i = 0;i < mid;i++) {
                left += str[i];
            }

            for(int i = mid+1;i < str.size();i++) {
                right += str[i];
            }
        }

        for(int i = 0;i < left.size();i++) {
            for(int j = 0;j < right.size();j++) {
                if(left[i] == right[j]) {
                    right[j] = '*';
                    break;
                }
            }    
        }

        int count = 0;
        for(int i = 0;i < right.size();i++) {
            if(right[i] == '*') {
                count++;
            }
        }

        
        
        if(count == right.size()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        
    }
    return 0;
}