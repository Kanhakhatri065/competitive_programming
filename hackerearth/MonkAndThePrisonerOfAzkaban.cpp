#include <bits/stdc++.h>

using namespace std;

void lastGreater(long long int arr[], long long int n, long long int last[]) {
    stack<long long int> s;

    for(long long int i = 0;i < n ;i++) {
        while(!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }

        if(!s.empty()) {
            last[i] = s.top();
        } else {
            last[i] = -1;
        }
        s.push(i);
    }
}

void nextSmaller(long long int arr[], long long int n, long long int next[]) {
    stack<long long int> s;

    for(long long int i = n - 1;i >= 0;i--) {
        while(!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }

        if(!s.empty()) {
            next[i] = s.top();
        } else {
            next[i] = -1;
        }
        s.push(i);
    }
}


int main() {
    long long int size; 
    cin >> size;

    long long int arr[size];
    for(long long int i = 0;i < size;i++) {
        cin >> arr[i];
    }

    long long int LG[size];
    lastGreater(arr, size, LG);

    long long int NS[size];
    nextSmaller(arr, size, NS);

    for(long long int i = 0;i < size;i++) {
        if(LG[i] != -1) {
            LG[i]++;
        }

        if(NS[i] != -1) {
            NS[i]++;
        }

        cout << (LG[i] + NS[i]) << " ";
    }

    cout << endl;
    
    return 0;
}

