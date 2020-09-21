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
int C, T, coefs[30], d, k;
int seq[1000000];
void prep() {
    int sum = 0;
    seq[0] = sum;
    for(int i = 0;;i++) {
        sum += i;
        if(sum >= 1000000) {
            break;
        }
        seq[sum] = i + 1;
    }
}

ull eval(int n, int i) {
    if(i == T) {
        return 0;
    }

    return coefs[i] * pow(n, i) + eval(n, i + 1);
}

int main() {
    go();
    sc(C);

    prep();
    while(C--) {
        sc(T);
        T++;
        for(int i = 0;i < T;i++) {
            sc(coefs[i]);
        }

        cin >> d >> k;

        int ind = (k - 1) / d;
        while(ind > 0 && seq[ind] == 0) {
            ind--;
        }

        ull ans = eval(seq[ind], 0);
        pf(ans);
    }

    return 0;
}