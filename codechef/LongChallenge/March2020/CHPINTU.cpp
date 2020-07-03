#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> i, pair<int,int> j) {
    return i.second < j.second;
}

int main() {

    int testcases;
    cin >> testcases;

    for(int i = 0;i < testcases; i++) {
        
        int baskets, types;
        cin >> baskets >> types;

        int different_types[baskets];
        for(int j = 0;j < baskets;j++) {
            cin >> different_types[j];
        }

        int different_prices[baskets];
        for(int j = 0;j < baskets;j++) {
            cin >> different_prices[j];
        }

        map<int, int> fruits;
        for(int j = 0; j < baskets;j++) {
            if(fruits.find(different_types[j]) != fruits.end()) {
                fruits[different_types[j]] += different_prices[j];
            } else {
                fruits[different_types[j]] = different_prices[j];
            }
        }

        pair<int, int> min_cost = *min_element(fruits.begin(), fruits.end(), compare);

        cout << min_cost.second << endl;
    }

    return 0;
}