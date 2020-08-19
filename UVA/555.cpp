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
map<char, int> suit;
map<char, int> deck;

bool myFunction(string i, string j) {
    if(suit[i[0]] == suit[j[0]]) {
        return deck[i[1]] < deck[j[1]];
    }

    return suit[i[0]] < suit[j[0]];
}

int main() {
    FAST_IO
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    suit['C'] = 0;
	suit['D'] = 1;
	suit['S'] = 2;
	suit['H'] = 3;
	
	deck['2'] = 2;
	deck['3'] = 3;
	deck['4'] = 4;
	deck['5'] = 5;
	deck['6'] = 6;
	deck['7'] = 7;
	deck['8'] = 8;
	deck['9'] = 9;
	deck['T'] = 10;
	deck['J'] = 11;
	deck['Q'] = 12;
	deck['K'] = 13;
	deck['A'] = 14;

    int current;
    char c;
    string dump;
    string cards, buffer;
    vector<string> players[4];
    map<char, int> dir;
    map<int, char> rdir;

    dir['S'] = 0;
	dir['W'] = 1;
	dir['N'] = 2;
	dir['E'] = 3;
	rdir[0] = 'S';
	rdir[1] = 'W';
	rdir[2] = 'N';
	rdir[3] = 'E';

    while(cin >> c) {
        if(c == '#') {
            return 0;
        }

        current = (dir[c] + 1) % 4;
        cin >> cards;
        cin >> buffer;
        cards += buffer;

        for(int i = 0;i < 13;i++) {
            for(int j = 0;j < 4;j++) {
                dump = cards.substr((i * 4 + j) * 2, 2);
                players[current].pb(dump);
                current = (current + 1) % 4;
            }
        }

        for(int i = 0;i < 4;i++) {
            sort(all(players[i]), myFunction);
            cout << rdir[i] << ":";
            for(auto it : players[i]) {
                cout << " " << it;
            }
            cout << endl;
            players[i].clear();
        }
    }

    return 0;
}