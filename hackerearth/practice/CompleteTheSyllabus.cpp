#include <iostream>

using namespace std;

int main(){
    string week[] = {"MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY","SATURDAY","SUNDAY"};

    int testcases;
    cin >> testcases;

    int work = 0;
    for(int i =  0;i < testcases;i++){
        cin >> work;

        int topics_per_week[7];
        for(int j = 0;j < 7;j++){
            cin >> topics_per_week[j];
        }

        int store_day = 0;
        int ittr = 0;
        while(work != 0){
            work -= topics_per_week[ittr];
            store_day = ittr;
            if(ittr == 6){
                ittr = 0;
            }
            ittr++;
        }

        cout << week[store_day] << endl;
    }
    return 0;
}