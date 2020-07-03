#include <iostream>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    long long int total_income = 0;
    for(int i = 0;i < testcases;i++){
        cin >> total_income;

        long long int net_income = 0;

        if(total_income > 0 && total_income <= 250000){
            net_income = total_income;
        } else if(total_income > 250000 && total_income <= 500000){
            net_income = total_income - 0.05 * (total_income - 250000);
        } else if(total_income > 500000 && total_income <= 750000){ 
            net_income = total_income - 0.10 * (total_income - 500000);
            net_income = net_income - 0.05 * 250000;
        } else if(total_income > 750000 && total_income <= 1000000){
            net_income = total_income - 0.15 * (total_income - 750000);
            net_income = net_income - 0.10 * 250000;
            net_income = net_income - 0.05 * 250000;
        } else if(total_income > 1000000 && total_income <= 1250000){
            net_income = total_income - 0.20 * (total_income - 1000000);
            net_income = net_income - 0.15 * 250000;
            net_income = net_income - 0.10 * 250000;
            net_income = net_income - 0.05 * 250000;
        } else if(total_income > 1250000 && total_income <= 1500000){
            net_income = total_income - 0.25 * (total_income - 1250000);
            net_income = net_income - 0.20 * 250000;
            net_income = net_income - 0.15 * 250000;
            net_income = net_income - 0.10 * 250000;
            net_income = net_income - 0.05 * 250000;
        } else if(total_income > 1500000){
            net_income = total_income - 0.30 * (total_income - 1500000);
            net_income = net_income - 0.25 * 250000;
            net_income = net_income - 0.20 * 250000;
            net_income = net_income - 0.15 * 250000;
            net_income = net_income - 0.10 * 250000;
            net_income = net_income - 0.05 * 250000;
        }

        cout << net_income << endl;
    }
    return 0;
}