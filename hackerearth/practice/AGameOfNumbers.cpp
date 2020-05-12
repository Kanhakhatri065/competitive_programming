#include <bits/stdc++.h>

using namespace std;

void nextGreater(long long int arr[], int n, int next[], char order) {
    stack<int> s;

    for(int i = n - 1;i >= 0;i--) {
        while(!s.empty() && ((order == 'G') ? arr[s.top()] <= arr[i] : arr[s.top()] >= arr[i])) {
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

void nextSmallerOfNextGreater(long long int arr[], int n) {
    int NG[n];
    int RS[n];

    nextGreater(arr, n, NG, 'G');
    nextGreater(arr, n, RS, 'S');

    for(int i = 0;i < n;i++) {
        if(NG[i] != -1 && RS[NG[i]] != -1) {
            cout << arr[RS[NG[i]]] << " ";
        } else {
            cout << "-1" << " ";
        }
    }

    cout << endl;
}

int main() {
    int size; 
    cin >> size;

    long long int arr[size];
    for(int i = 0;i < size;i++) {
        cin >> arr[i];
    }

    nextSmallerOfNextGreater(arr, size);

    return 0;
}

