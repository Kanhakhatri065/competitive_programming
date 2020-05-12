#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    int size, queries;
    for(int i = 0;i < testcases;i++) {
        cin >> size >> queries;

        long long int arr[size];
        for(int j = 0;j < size;j++) {
            cin >> arr[j];
        }

        int left, right;
        for(int j = 0;j < queries;j++) {
            cin >> left >> right;

            int subsequence_size = right - left + 1;

            vector<long long int> subsequence;
            for(int k = left - 1;k < subsequence_size;k++) {
                subsequence.push_back(arr[k]);
            }

            
        }
    }

    return 0;
}