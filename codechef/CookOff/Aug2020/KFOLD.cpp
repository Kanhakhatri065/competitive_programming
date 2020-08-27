#include <iostream>

using namespace std;

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);

    string s;
    cin >> s;

    int zeros = 0, ones = 0;
    for(int i = 0;i < n;i++) {
        if(s[i] == '0') {
            zeros++;
        } else {
            ones++;
        }
    }

    if(ones == n || zeros == n) {
        cout << s << endl;
    } else {
        int div = n / k;
       
        if(zeros % div || ones % div) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            zeros /= div;
            ones /= div;

            string out = "", rep = "", rev_rep = "";
            for(int i = 0;i < zeros;i++) {
                rep += '0';
            }

            for(int i = 0;i < ones;i++) {
                rep += '1';
            }

            for(int i = int(rep.size()) - 1;i >= 0;i--) {
                rev_rep += rep[i];
            }

            int cnt = 0;
            while(int(out.size()) < n) {
                if(cnt & 1) {
                    out += rev_rep;
                } else {
                    out += rep;
                }
                cnt++;
            }

            //cout << "ans : ";
            cout << out << endl;
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        solve();
    }

    return 0;
}