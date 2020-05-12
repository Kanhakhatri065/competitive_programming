#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    int suvo,suvojit;
    string str;
    for(int i = 0;i < testcases;i++) {
        cin >> str;
        
        suvo = 0, suvojit = 0;

        vector<int> suvo_start_index;
        vector<int> suvojit_start_index;

        string str1 = "SUVO";
        string str2 = "SUVOJIT";

        for(int j = 0;j <= str.length() - str1.length();j++) {
            int k;
            for(k = 0;k < str1.length();k++) {
                if(str[j + k] != str1[k]) {
                    break;
                }
            }

            if(k == str1.length()) {
                suvo_start_index.push_back(j);
            }

        }

        for(int j = 0;j <= str.length() - str2.length();j++) {
            int k;
            for(k = 0;k < str2.length();k++) {
                if(str[j + k] != str2[k]) {
                    break;
                }
            }

            if(k == str2.length()) {
                suvojit_start_index.push_back(j);
            }
        }

        for(int j = 0;j < suvo_start_index.size();j++) {
            for(int k = 0;k < suvojit_start_index.size();k++) {
                if(suvo_start_index[j] == suvojit_start_index[k]) {
                    suvo_start_index[j] = -1;
                    break;
                }
            }
        }

        for(int j = 0;j < suvo_start_index.size();j++) {
            if(suvo_start_index[j] >= 0) {
                suvo++;
            } 
        }

        suvojit = suvojit_start_index.size();

        cout << "SUVO = " << suvo << ", SUVOJIT = " << suvojit << endl;
    }

    return 0;
}