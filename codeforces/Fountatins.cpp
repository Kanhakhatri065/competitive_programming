#include <bits/stdc++.h>

using namespace std;
 
int main() {
    int num, coins, diamonds;
    cin >> num >> coins >> diamonds;

    multimap<int, int> coin_beauty;
    multimap<int, int> diamond_beauty;

    int beauty, cost;
    char type;
    for(int i = 0;i < num;i++) {
        cin >> beauty >> cost >> type;
        if(type == 'C') {
            coin_beauty.insert(make_pair(beauty, cost));
        } else {
            diamond_beauty.insert(make_pair(beauty, cost));
        }
    }

    int beauty_coin = 0;
    int beauty_diamond = 0;
    long long int total_beauty = 0;

    multimap<int,int>::reverse_iterator it;
    for(it = coin_beauty.rbegin();it != coin_beauty.rend();it++) {
        if(it->second <= coins) {
            beauty_coin += it->first;
        }
    }

    for(it = diamond_beauty.rbegin();it != diamond_beauty.rend();it++) {
        if(it->second <= diamonds) {
            beauty_diamond += it->first;
        }
    }

    if(beauty_coin != 0 && beauty_diamond) {
        total_beauty += beauty_coin;
        total_beauty += beauty_diamond;
    }

    cout << total_beauty << endl;

    return 0;
}