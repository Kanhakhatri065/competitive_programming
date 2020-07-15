/*** I came, I saw, I conquered. ***/
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;typedef unsigned long long ull;
/*** Input Output ***/
#define sc(a) cin >> a
#define pf(a) cout << a << endl
/*** Loops ***/
#define f(i, p, num) for(ll i = p; i < num; i++)
#define forIn(arr, num) for(ll i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
/*** Define Values ***/
#define mod1 1000000007
#define mod2 998244353
#define eps 1e-7
/*** Abbrevations **/
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define mem(name, value) memset(name, value, sizeof(name))
#define pp pair
/*** STLs ***/
typedef vector<ll>vll;typedef set<ll>sll;typedef multiset<ll>msll;
typedef queue<ll>qll;typedef map<ll,ll>mll;typedef pair<ll,ll>pll;
typedef vector<pair<ll,ll>>vpll;
/*** Sorts ***/
#define all(v) (v).begin(), (v).end()
#define srt(v) sort(all(v))
#define srtGreat(v) sort(all(v), greater<ll>())
/*** Bit-Stuff ***/
#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
/*** Some Prints ***/
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
/*----------------------------------------------------------------*/
const int inf = 1e9 + 8;
int N;
int a[100010];
int Min[100010][18];
int Max[100010][18];

int two(int n) {
    return 1 << n;
}

int log(int n) {
    int i = 0;
    while(two(i) <= n) {
        i++;
    }

    return i - 1;
}

void solve() {
    sc(N);

    f(i, 0, N) {
        sc(a[i]);
        Min[i][0] = Max[i][0] = i;
    }

    //preprocess for finding minimum, O(N * logN)
    for(int j = 1;two(j) <= N;j++) {
        for(int i = 0;i + two(j) -1 < N;i++) {
            if(a[Min[i][j - 1]] < a[Min[i + two(j - 1)][j - 1]]) {
                Min[i][j] = Min[i][j - 1]; 
            } else {
                Min[i][j] = Min[i + two(j - 1)][j - 1];
            }
        }
    }

    //preprocess for finding maximum, O(N * logN)
    for(int j = 1;two(j) <= N;j++) {
        for(int i = 0;i +two(j) - 1 < N;i++) {
            if(a[Max[i][j - 1]] > a[Max[i + two(j - 1)][j - 1]]) {
                Max[i][j] = Max[i][j - 1];
            } else {
                Max[i][j] = Max[i + two(j - 1)][j - 1];
            }
        }
    }

    int Q;
    sc(Q);
    
    int L, R;
    while(Q--) {
        //Answering each query in O(1), although intended solution should be able to answer in O(logN).
        sc(L);
        sc(R); 
        //finding min and max required-time in asked range
        int k = (int)log(R - L + 1);

        //finding min between [L, R]
        int _min = 0;
        _min = min(a[Min[L][k]], a[Min[R - two(k) + 1][k]]);

        //findig max between [L, R]
        int _max = 0;
        _max = max(a[Max[L][k]], a[Max[R - two(k) + 1][k]]);
        
        //the time in which all matchsticks between [L, R] will burn down.
        //notice (_max - _min) / 2.0 , since both ends are lighted.
        double time1 = _min + (_max - _min) / 2.0;

        //Find maximum in remaining time.
        int tmp_max = INT_MIN;
        if(L > 0) {
            //max in range[0, L - 1] if L - 1 is non-negative
            int tmpR = L - 1;
            L = 0;
            k = (int) log(tmpR - L + 1);

            tmp_max = max(a[Max[L][k]], a[Max[tmpR - two(k) + 1][k]]);
        }

        if(R < N - 1) {
            //max in range [R + 1, N -1] if R is less than N - 1
            L = R + 1;
            R = N - 1;
            k = (int) log(R - L + 1);
            if(a[Max[L][k]] >= a[Max[R - two(k) + 1][k]]) {
                if(a[Max[L][k]] >= tmp_max) {
                    tmp_max = a[Max[L][k]];
                }
            } else {
                if(a[Max[R - two(k) + 1][k]] >= tmp_max) {
                    tmp_max = a[Max[R - two(k) + 1][k]];
                }
            }
        }

        //the time in which all matchsticks in remaining range will be burned down.
        double time2 = 1.0 * tmp_max + _min;

        printf("%.1f\n", max(time1, time2));
    }
}

int main() {
    FAST_IO
    solve();
    return 0;
}