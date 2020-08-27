#include <iostream>

using namespace std;
void solve() {
    string s;
    cin >> s;
    
    int x, y;
    scanf("%d %d", &x, &y);

    int r = 0, l = 0, u = 0, d = 0;
    int n = int(s.size());
    for(int i = 0;i < n;i++) {
        if(s[i] == 'U') {
            u++;
        } else if(s[i] == 'D') {
            d++;
        } else if(s[i] == 'R') {
            r++;
        } else {
            l++;
        }
    }

    int q;
    scanf("%d", &q);

    int x1, y1;
    bool flag;
    long long cnt;
    while(q--) {
        scanf("%d %d", &x1, &y1);

        flag = true;
        cnt = 0LL;
        if(x1 > x) {
            if(r < x1 - x) {
                flag = false;
            } else {
                cnt += (x1 - x);
            }
        } else if(x1 < x) {
            if(l < x - x1) {
                flag = false;
            } else {
                cnt += (x - x1);
            }
        }

        if(y1 > y) {
            if(u < y1 - y) {
                flag = false;
            } else {
                cnt += (y1 - y);
            }
        } else {
            if(d < y - y1) {
                flag = false;
            } else {
                cnt += (y - y1);
            }
        }

        if(flag) {
            printf("YES %lld\n", cnt);
        } else {
            printf("NO\n");
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