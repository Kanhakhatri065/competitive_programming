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
#define mem(name, value) memset(name, value, sizeof(name))
/*** STLs ***/
typedef vector<ll>vll;typedef set<ll>sll;typedef multiset<ll>msll;
typedef map<ll,ll>mll;typedef pair<ll,ll>pll;
/*** Sorts ***/
#define all(v) (v).begin(), (v).end()
#define srt(v) sort(all(v))
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
bool alldiff(int n, int m) {
    if(n >= 100000) {
        return false;
    }

    int arr[10];
    mem(arr, 0);
    
    if(m < 10000) {
        arr[0]++;
    }

    int tmp = n;
    while(tmp) {
        arr[(tmp % 10)]++;
        tmp /= 10;
    }

    tmp = m;
    while(tmp) {
        arr[(tmp % 10)]++;
        tmp /= 10;
    }

    for(int i = 0;i < 10;i++) {
        if(arr[i] == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    FAST_IO
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int n, count = 0;
    while(cin >> n) {
        if(!n) {
            break;
        }

        int num, denum;
        bool found = false;
        count++;

        if(count > 1) {
            printf("\n");
        }

        for(denum = 1234;denum < 50000;denum++) {
            num = denum * n;
            if(alldiff(num, denum)) {
                printf("%05d / %05d = %d\n", num, denum, n);
                found = true;
            }
        }

        if(!found) {
            printf("There are no solutions for %d.\n", n);
        }
    }

    return 0;
}