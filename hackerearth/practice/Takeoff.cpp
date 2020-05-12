#include <bits/stdc++.h>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    for(int i = 0;i < testcases;i++){
        int n, p, q, r;
        cin >> n >> p >> q >> r;
        int total = 0;
        for(int j = 1;j <= n;j++){
            if((j%p == 0) && (j%q != 0) && (j %r != 0)){
                total++;
            } else if((j%p != 0) && (j%q == 0) && (j%r != 0)){
                total++;
            } else if((j%p != 0) && (j%q != 0) && (j%r == 0)){
                total++;
            }
        }

        cout << total << endl;
    }
    return 0;
}