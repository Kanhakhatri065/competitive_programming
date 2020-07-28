#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    int size;
    while(testcases--) {
        cin >> size;

        vector<int> cost(size, 0);
        for(int i = 0;i < size;i++) {
            cin >> cost[i];
        }

        vector<int> petrol(size, 0);
        for(int i= 0;i < size;i++) {
            cin >> petrol[i];
        }

        long long int minCost = 0;
        long long int mi = 1000000000LL;
        long long int sum_l = 0;
        for(int i = 0;i < size;i++) {
            if(cost[i] < mi) {
                if(i != 0) {
                    minCost += mi * sum_l;
                }
                sum_l = petrol[i];
                mi = cost[i];
            } else {
                sum_l += petrol[i];
            }
        }
        minCost += mi * sum_l;
        

        cout << minCost << endl;
    }
    return 0;
}