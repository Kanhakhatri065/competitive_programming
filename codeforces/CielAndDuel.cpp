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
/*** Swapping ***/
void swapll(ll *a,ll *b){ll tmp=*a;*a=*b;*b=tmp;}
void swapc(char *a,char *b){char tmp=*a;*a=*b;*b=tmp;}
/*----------------------------------------------------------------*/
void solve() {
    ll n, m;
    sc(n);
    sc(m);

    vll atk;
    vll def;

    ll power;
    string type;
    f(i, 0, n) {
        sc(type);
        sc(power);

        if(type == "ATK") {
            atk.pb(power);
        } else {
            def.pb(power);
        }
    }

    vll ciel(m);
    forIn(ciel, m);

    srtGreat(ciel);
    srt(atk);
    srt(def);

    ll idx_atk = 0;
    ll total_damage = 0;
    ll i = 0;
    for(i = 0; i < m;i++) {
        if(idx_atk < atk.size()) {
            if(atk[idx_atk] <= ciel[i]) {
                total_damage += (ciel[i] - atk[idx_atk]);
                idx_atk++;
            } else {
                break;
            }
        } else {
            break;
        }
    }

    ll collect = 0;
    ll idx_def = 0;
    for(ll j = m - 1;j >= i && idx_atk == atk.size();j--) {
        if(idx_def < def.size()) {
            if(def[idx_def] < ciel[j]) {
                idx_def++;
            } else {
                collect += ciel[j];
            }
        } else {
            total_damage += ciel[j];
        }
    }

    if(idx_def == def.size()) {
        total_damage += collect;
    }

    idx_atk = 0, idx_def = 0, collect = 0;
    ll total_damage2 = 0;
    for(ll j = m - 1;j >= 0;j--) {
        if(idx_def < def.size()) {
            if(def[idx_def] < ciel[j]) {
                idx_def++;
                ciel[j] = 0;
            }
        } else {
            break;
        }
    }

    for(i = m - 1;i >= 0 && idx_def == def.size();i--) {
        if(idx_atk < atk.size()) {
            if(atk[idx_atk] <= ciel[i]) {
                total_damage2 += (ciel[i] - atk[idx_atk]);
                idx_atk++;
            } else {
                collect += ciel[i];
            }
        } else {
            total_damage2 += ciel[i];
        }
    }

    if(idx_atk == atk.size()) {
        total_damage2 += collect;
    }

    pf(max(total_damage2, total_damage));
}

int main() {
    FAST_IO
    solve();
    return 0;
}