#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    testcases++;

    vector<string> inputs;
    string temp;
    for(int i = 1;i <= testcases;i++) {
        getline(cin, temp);
        inputs.push_back(temp);
    }
    

    for(int i = 0;i < testcases;i++) {
        istringstream iss(inputs[i]);

        vector<string> splited;
        for(string s;iss >> s;) {
            splited.push_back(s);
        }

        vector<vector<string>> size_table(51);
        for(int j = 0;j < splited.size();j++) {
            size_table[splited[j].size()].push_back(splited[j]);
        }

        for(int j = 0;j < size_table.size();j++) {
            if(size_table[j].size() != 0) {
                for(int k = 0;k < size_table[j].size();k++) {
                    cout << size_table[j][k] << " ";
                }
            } 
        }
        cout << endl;
    }

    return 0;
}