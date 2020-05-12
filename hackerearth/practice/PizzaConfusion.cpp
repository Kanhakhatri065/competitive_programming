#include <bits/stdc++.h>

using namespace std;

struct Pizza {
    string store_name;
    long long int points;
};

int main() {
    int num_of_stores;
    cin >> num_of_stores;

    Pizza pizzas[num_of_stores];
    for(int i = 0;i < num_of_stores;i++) {
        cin >> pizzas[i].store_name >> pizzas[i].points;
    }

    Pizza temp;
    for(int i = 0;i < num_of_stores - 1;i++) {
        for(int j = 0;j < num_of_stores - i - 1;j++) {
            if(pizzas[j].points > pizzas[j + 1].points) {
                temp = pizzas[j];
                pizzas[j] = pizzas[j + 1];
                pizzas[j + 1] = temp;
            } else if(pizzas[j].points == pizzas[j + 1].points) {
                if(pizzas[j].store_name < pizzas[j + 1].store_name) {
                    temp = pizzas[j];
                    pizzas[j] = pizzas[j + 1];
                    pizzas[j + 1] = temp;
                }
            }
        }
    }

    cout << pizzas[num_of_stores - 1].store_name << endl;

    return 0;
}