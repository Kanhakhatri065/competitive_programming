#include <iostream>

using namespace std;

int main() {
    int size;
    cin >> size;

    string game;
    cin >> game;

    int anton = 0;
    int danik = 0;
    for(int i = 0;i < game.length();i++) {
        if(game[i] == 'A') {
            anton++;
        } else if(game[i] == 'D') {
            danik++;
        }
    }

    if(anton > danik) {
        cout << "Anton" << endl;
    } else if(anton < danik) {
        cout << "Danik" << endl;
    } else {
        cout << "Friendship" << endl;
    }

    return 0;
}