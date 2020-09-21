/*** I came, I saw, I conquered. ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef unsigned long long ull;
#define sc(a) cin >> a
#define pf(a) cout << a << endl
#define forIn(arr, num) for(ll i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
#define mod 1000000007
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
void go() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
/*----------------------------------------------------------------*/
vector<string> v1, v2, v3, v4;
void precomputation() {
    string s1(2, ' ');
    for(int i = 0;i < 10;i++) {
        for(int j = 0;j < 10;j++) {
            if((i + j) * (i + j) == (i * 10 + j)) {
                s1[0] = '0' + i;
                s1[1] = '0' + j;
                v1.pb(s1);
            }
        }
    }

    string s2(4, ' ');
    for(int i = 0;i < 100;i++) {
        for(int j = 0;j < 100;j++) {
            if((i + j) * (i + j) == (i * 100 + j)) {
                s2[0] = '0' + i / 10;
                s2[1] = '0' + i % 10;
                s2[2] = '0' + j / 10;
                s2[3] = '0' + j % 10;
                v2.pb(s2);
            }
        }
    }

    string s3(6, ' ');
    for(int i = 0;i < 1000;i++) {
        for(int j = 0;j < 1000;j++) {
            if((i + j) * (i + j) == (i * 1000 + j)) {
                s3[0] = '0' + i / 100;
                s3[1] = '0' + (i % 100) / 10;
                s3[2] = '0' + i % 10;
                s3[3] = '0' + j / 100;
                s3[4] = '0' + (j % 100) / 10;
                s3[5] = '0' + j % 10;
                v3.pb(s3);
            }
        }
    }

    string s4(8,' ');
    
    for(int i=0;i<10000;i++){
        for(int j=0;j<10000;j++){
            if((i+j)*(i+j)==i*10000+j){
                s4[0]='0'+i/1000;
                s4[1]='0'+i/100%10;
                s4[2]='0'+i/10%10;
                s4[3]='0'+i%10;
                s4[4]='0'+j/1000;
                s4[5]='0'+j/100%10;
                s4[6]='0'+j/10%10;
                s4[7]='0'+j%10;
                v4.push_back(s4);
            }
        }
    }
}

void solve() {
    precomputation();
    int n;
    while(cin >> n) {
        if(n == 2) {
            for(auto it : v1) {
                cout << it << endl;
            }
        } else if(n == 4) {
            for(auto it : v2) {
                cout << it << endl;
            }
        } else if(n == 6) {
            for(auto it : v3) { 
                cout << it << endl;
            }
        } else {
            for(auto it : v4) {
                cout << it << endl;
            }
        }
    }
}

int main() {
    go();
    solve();
    return 0;
}