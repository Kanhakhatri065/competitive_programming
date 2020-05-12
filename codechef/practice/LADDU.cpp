#include <iostream>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    int activities;
    string user;

    long long int count = 0;
    while(testcases--) {
        count = 0;

        cin >> activities >> user;
        
        string activity;
        int var;
        for(int i = 0;i < activities;i++) {
            cin >> activity;
            if(activity == "CONTEST_WON") {
                cin >> var;
                if(var <= 20) {
                    count += (300 + (20 - var));
                } else {
                    count += 300;
                }
            } else if(activity == "TOP_CONTRIBUTOR") {
                count += 300;
            } else if(activity == "BUG_FOUND") {
                cin >> var;
                count += var;
            } else if(activity == "CONTEST_HOSTED") {
                count += 50;
            }
        }

        int months;
        if(user == "INDIAN") {
            months = count / 200;
        } else {
            months = count / 400;
        }

        cout << months << endl;
    }
    return 0;
}