#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    for(int i = 0;i < testcases;i++){
        int size;
        cin >> size;

        int rupam[size];
        for(int j = 0;j < size;j++){
            cin >> rupam[j];
        }    

        int ankit[size];
        for(int j = 0;j < size;j++){
            cin >> ankit[j];
        }

        sort(rupam , rupam + size);
        sort(ankit, ankit + size);

        int max_count_rupam = 1, rupam_heaviest = rupam[0], current_count = 1;
        for(int j = 1;j < size;j++){
            if(rupam[j] == rupam[j - 1]){
                current_count++;
            } else {
                if(current_count > max_count_rupam){
                    max_count_rupam = current_count;
                    rupam_heaviest = rupam[j - 1];
                }
                current_count = 1;
            }
        }

        if(current_count > max_count_rupam){
            max_count_rupam = current_count;
            rupam_heaviest = rupam[size - 1];
        }

        current_count = 1;
        int max_count_ankit = 1, ankit_heaviest = ankit[0];
        for(int j = 1;j < size;j++){
            if(ankit[j] == ankit[j - 1]){
                current_count++;
            } else {
                if(current_count > max_count_ankit){
                    max_count_ankit = current_count;
                    ankit_heaviest = ankit[j - 1];
                }
                current_count = 1;
            }
        }

        if(current_count > max_count_ankit){
            max_count_ankit = current_count;
            ankit_heaviest = ankit[size - 1];
        }
        cout << "Rupam Heaviest : " << rupam_heaviest << endl;
        cout << "Ankit Heaviest : " << ankit_heaviest << endl;
        cout << "Rupam max count : " << max_count_rupam << endl;
        cout << "Ankit max count : " << max_count_ankit << endl;
        
        if(rupam_heaviest > ankit_heaviest){
            cout << "Rupam" << endl;
        } else if(rupam_heaviest < ankit_heaviest){
            cout << "Ankit" << endl;
        } else {
            if(max_count_rupam > max_count_ankit){
                cout << "Rupam" << endl;
            } else if(max_count_rupam < max_count_ankit){
                cout << "Ankit" << endl;
            } else {
                cout << "Tie" << endl;
            }
        }
        
    }
    return 0;
}