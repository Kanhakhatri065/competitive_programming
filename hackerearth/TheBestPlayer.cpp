#include <bits/stdc++.h>

using namespace std;

struct Fan {
    string name;
    int score;
};

int main() {
    int num_of_fans, max_meet;
    cin >> num_of_fans >> max_meet;

    Fan fans[num_of_fans];
    for(int i = 0;i < num_of_fans;i++) {
        cin >> fans[i].name >> fans[i].score;
    }
    
    Fan temp;
    for(int i = 0;i < num_of_fans - 1;i++) {
        for(int j = 0;j < num_of_fans - i - 1;j++) {
            if(fans[j].score > fans[j + 1].score) {
                temp = fans[j];
                fans[j] = fans[j + 1];
                fans[j + 1] = temp;
            } else if(fans[j].score == fans[j + 1].score) {
                if(fans[j].name < fans[j + 1].name) {
                    temp = fans[j];
                    fans[j] = fans[j + 1];
                    fans[j + 1] = temp;
                }
            }
        }
    }

    int maxi = num_of_fans - 1;
    while(max_meet > 0) {
        cout << fans[maxi].name << endl;
        max_meet--;
        maxi--;
    }

    return 0; 
}