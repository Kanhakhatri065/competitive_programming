#include <bits/stdc++.h>

using namespace std;

int main(){
    int size;
    cin >> size;

    string names[size];
    int hours[size];

    for(int i = 0;i < size;i++){
        cin >> names[i] >> hours[i];
    }

    int hourTemp;
    string nameTemp;
    for(int i = 0;i < size -1 ;i++){
        for(int j = 0;j < size - i - 1;j++){
            if(hours[j] > hours[j+1]){
                hourTemp = hours[j];
                hours[j] = hours[j+1];
                hours[j+1] = hourTemp;

                nameTemp = names[j];
                names[j] = names[j+1];
                names[j+1] = nameTemp;
            }
        }
    }

    cout << names[size-1] << endl;
    cout << names[size - 2] << endl;
    cout << names[size - 3] << endl;
    
    return 0;
}