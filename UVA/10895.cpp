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
vector<vector<pair<int,int>>> vec;
vector<vector<pair<int, int>>> adj;

void setRow(vector<int> vIndex, vector<int> vValue, int rowIndex) {
    pair<int, int> tmp;
    
    for(int i = 0;i < int(vIndex.size());i++) {
        tmp.ff = vIndex[i];
        tmp.ss = vValue[i];
        vec[rowIndex].pb(tmp);
    }
}

void printAnswer(int rows, int cols) {
    vector<pair<int, int>> answerRow;
    cout << cols << ' ' << rows << endl;

    for(int i = 0;i < int(adj.size());i++) {
        answerRow = adj[i];

        if(answerRow.empty()) {
            cout << "0\n\n";
        } else {
            cout << int(answerRow.size());

            for(int j = 0;j < int(answerRow.size());j++) {
                cout << " " << (answerRow[j].ff + 1);
            }

            cout << endl;

            for(int j = 0;j < int(answerRow.size());j++) {
                if(j < int(answerRow.size()) - 1) {
                    cout << answerRow[j].ss << " ";
                } else {
                    cout << answerRow[j].ss << endl;
                }
            }
        }
    }
}

int main() {
    FAST_IO
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int rows, cols, not_empty, val;
    vector<int> vIndex, vValue;
    pair<int, int> tmp, tmpA;
    string trash;

    while(cin >> rows >> cols) {
        vec.assign(rows, vector<pair<int, int>>());
        adj.assign(cols, vector<pair<int, int>>());

        for(int i = 0;i < rows;i++) {
            cin >> not_empty;
            if(!not_empty) {
                getline(cin, trash);
                continue;
            }

            for(int j = 0;j < not_empty;j++) {
                cin >> val;
                vIndex.pb(val - 1);
            }

            for(int j = 0;j < not_empty;j++) {
                cin >> val;
                vValue.pb(val);
            }

            setRow(vIndex, vValue, i);
            vIndex.clear();
            vValue.clear();
        }

        for(int i = 0;i < int(vec.size());i++) {
            for(int j = 0;j < int(vec[i].size());j++) {
                tmp = vec[i][j];
                tmpA.ff = i;
                tmpA.ss = tmp.ss;

                adj[tmp.ff].pb(tmpA);
            }
        }

        printAnswer(rows, cols);
    }

    return 0;
}