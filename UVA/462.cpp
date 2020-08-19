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
int main() {
    FAST_IO
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    map<char, int> suitConversion;
    suitConversion['S'] = 0;
    suitConversion['H'] = 1;
    suitConversion['D'] = 2;
    suitConversion['C'] = 3;

    char back[4] = {'S', 'H', 'D', 'C'};

    bool ace[4], king[4], queen[4], jack[4], trump[4];
    int count[4], points, specialPoints, pos;

    string temp;
    while(cin >> temp) {
        mem(ace, false);
        mem(king, false);
        mem(queen, false);
        mem(jack, false);
        mem(trump, false);
        mem(count, 0);

        points = specialPoints = 0;

        for(int i = 0;i < 13;i++) {
            if(i != 0) {
                cin >> temp;
            }

            pos = suitConversion[temp[1]];

            if(temp[0] == 'A') {
                ace[pos] = true;
                points += 4;
            } else if(temp[0] == 'K') {
                king[pos] = true;
                points += 3;
            } else if(temp[0] == 'Q') {
                queen[pos] = true;
                points += 2;
            } else if(temp[0] == 'J') {
                jack[pos] = true;
                points += 1;
            }

            count[pos]++;
        }

        for(int i = 0;i < 4;i++) {
            if(ace[i]) {
                trump[i] = true;
            }

            if(king[i] && count[i] < 2) {
                points--;
            } else if(king[i]) {
                trump[i] = true;
            }

            if(queen[i] && count[i] < 3) {
                points--;
            } else if(queen[i]) {
                trump[i] = true;
            }

            if(jack[i] && count[i] < 4) {
                points--;
            }

            if(count[i] == 2) {
                specialPoints++;
            } else if(count[i] < 2) {
                specialPoints += 2;
            }
        }

        if(trump[0] && trump[1] && trump[2] && trump[3] && points >= 16) {
            cout << "BID NO-TRUMP" << endl;
        } else if(points + specialPoints >= 14) {
            char output = 'S';
            int mx = 0;
            for(int i = 1;i < 4;i++) {
                if(count[i] > count[mx]) {
                    mx = i;
                    output = back[i];
                }
            }

            cout << "BID " << output << endl;
        } else {
            cout << "PASS" << endl;
        }
    }

    return 0;
}