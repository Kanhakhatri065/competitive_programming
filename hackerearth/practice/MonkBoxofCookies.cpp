#include <bits/stdc++.h>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;
    for(int i = 0;i < testcases;i++){
        int size;
        cin >> size;
        
        long long number;
        vector<int> count(32,0);
        
        for(int j = 0;j < size;j++){
            cin >> number;
            for(int k = 0;k < 32;k++){
                if(number & (1 << k)){
                    count[k]++;
                }
            }

        }
        cout << distance(count.begin(),max_element(count.begin(),count.end())) << endl;
    }
    return 0;
}