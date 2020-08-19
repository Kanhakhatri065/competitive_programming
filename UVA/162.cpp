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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    map<char, int> fcount;
    fcount['A'] = 4;
    fcount['K'] = 3;
    fcount['Q'] = 2;
    fcount['J'] = 1;
    while(true) {
        deque<char> p[2];
        for (int i = 1; i <= 52; ++i) {
            string card;
            cin >> card;
            if (card == "#")
                return 0;

            p[i % 2].push_front(card[1]);
        }

        deque<char> deck;
        int turn = 1;
        int last_face = -1;
        int cover_count = 0;
        while (true) {
            if (p[turn].empty())
                break;
            char card = p[turn].front();
            p[turn].pop_front();
            deck.push_front(card);

            if (fcount.count(card)) {
                last_face = turn;
                cover_count = fcount[card] + 1;
                turn = (turn + 1) % 2;
            }

            if (cover_count) {
                --cover_count;

                if (!cover_count) {
                while (!deck.empty()) {
                    p[last_face].push_back(deck.back());
                    deck.pop_back();
                }

                turn = last_face;
                }
            } else {
                turn = (turn + 1) % 2;
            }
        }

        int winner = (turn + 1) % 2;
        printf("%d%3d\n", winner + 1, int(p[winner].size()));
    }
    
    return 0;
}