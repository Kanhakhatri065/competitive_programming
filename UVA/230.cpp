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
void solve() {
    string line;
    map<string, int> books;
    vector<pair<string, string>> shelf;

    while(getline(cin, line) && line[0] != 'E') {
        string title;
        string author;

        istringstream in(line);
        in.ignore(1, '"');
        getline(in, title, '"');

        in.ignore(1, ' ');
        in.ignore(2, ' ');
        getline(in, author, '"');

        shelf.pb({author, title});
    }

    int shelf_size = int(shelf.size());
    srt(shelf);

    for(int i = 0;i < shelf_size;i++) {
        books[shelf[i].ss] = i;
    }

    vector<bool> borrowed(shelf_size);
	vector<bool> returned(shelf_size);

    while(getline(cin, line) && line[0] != 'E') {
        string title;
        int previousBook = -1;

        istringstream in(line);

        if(line[0] != 'S') {
            in.ignore(8, '\"');
            getline(in, title, '\"');
        }

        if(line[0] == 'B') {
            borrowed[books[title]] = true;
            returned[books[title]] = false;
        } else if(line[0] == 'R') {
            returned[books[title]] = true;
        } else {
            for(int i = 0;i < shelf_size;i++) {
                if(returned[i]) {
                    if(previousBook != -1) {
                        cout << "Put \"" << shelf[i].ss << "\" after \"" << shelf[previousBook].ss << "\"" << endl;
                    } else {
                        cout << "Put \"" << shelf[i].ss << "\" first" << endl;
                    }

                    returned[i] = false;
                    borrowed[i] = false;
						
                    previousBook = i;
                } else if(!borrowed[i]) {
                    previousBook = i;
                }
            }

            cout << "END" << endl;
        }
    }
}

int main() {
    FAST_IO
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
    return 0;
}