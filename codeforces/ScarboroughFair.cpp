#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string str;
    cin >> str;

    int l, r;
    char replace_this, replace_with;
    while(m--) {
        cin >> l >> r >> replace_this >> replace_with;
        for(int i = l - 1;i < r;i++) {
            if(str[i] == replace_this) {
                str[i] = replace_with;
            }
        }
    }

    cout << str << endl;

    return 0;
}