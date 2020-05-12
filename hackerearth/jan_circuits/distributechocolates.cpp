#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcases;
    cin >> testcases;

    for(int i = 0;i < testcases;i++){
        int num_chocolates,num_students;
        cin >> num_chocolates >> num_students;
        
        int last_time = num_chocolates;

        for(int j = 1;j < num_chocolates;j++){
            int sum = num_students * j + (((num_students - 1)*(num_students)) / 2);
            if(sum <= num_chocolates){
                last_time = sum;
            }

            if(sum > num_chocolates){
                break;
            }
        }   

        if(last_time == num_chocolates){
            cout << last_time << endl;
        } else {
            cout << (num_chocolates - last_time) << endl;
        }
    }

    return 0;
}