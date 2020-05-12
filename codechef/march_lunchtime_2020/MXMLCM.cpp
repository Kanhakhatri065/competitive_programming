#include <bits/stdc++.h>

using namespace std;

long long int gcd(long long int a, long long int b) {
    if(a == 0) {
        return b;
    }

    return gcd(b % a, a);
}

long long int lcm(long long int a, long long int b) {
    return ((a * b) / gcd(a, b));
}

int main() {
    int testcases;
    cin >> testcases;

    for(int i = 0;i < testcases;i++) {
        int n, m;
        cin >> n >> m;

        int arr[n];
        for(int j = 0;j < n;j++) {
            cin >> arr[j];
        }  

        long long int lcm_sequence = lcm(1, arr[0]);
        for(int j = 1;j < n;j++) {
            lcm_sequence = lcm(lcm_sequence, arr[1]);
        }
        
        map<long long int, vector<long long int>> store;
        
        long long int gcd_max_element = 0;
        for(int j = 1;j <= m;j++) {
            gcd_max_element = gcd(lcm_sequence, j);
            store[gcd_max_element].push_back(j);
        }

        vector<long long int> temp;

        long long int output;

        map<long long int, vector<long long int>>::iterator it;

        it = store.begin();
        temp = it->second;

        sort(temp.begin(), temp.end());

        output = temp[temp.size() - 1];

        cout << output << endl;
    }
    
    return 0;
}