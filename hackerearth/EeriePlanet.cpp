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
const int MAX = 1e5 + 5;
int guardHeights[MAX], queryHeights[MAX], invalid[MAX], ans[MAX];

struct Node {
    bool query;
    int timer;
    bool start;
    int id;
    Node(bool query, int timer, bool start, int id) : query(query), timer(timer), start(start), id(id) {

    }
};

bool cmp(Node a, Node b) {
    if(a.timer != b.timer) {
        return a.timer < b.timer;
    }

    return a.query < b.query;
}

void solve() {
    int h, c, q;
    cin >> h >> c >> q;
    
    vector<Node> timeSortedQueries;
    priority_queue<pair<int, int>> pq;
    pair<int, int> tp;

    int start, end;
    for(int i = 0;i < c;i++) {
        cin >> guardHeights[i] >> start >> end;
        timeSortedQueries.pb(Node(0, start, 1, i));
        timeSortedQueries.pb(Node(0, end + 1, 0, i));
    }

    for(int i = 0;i < q;i++) {
        cin >> queryHeights[i] >> start;
        timeSortedQueries.pb(Node(1, start, 0, i));
    }

    sort(all(timeSortedQueries), cmp);

    for(auto el : timeSortedQueries) {
        if(!el.query) {
            if(el.start) {
                pq.push({guardHeights[el.id], el.id});
            } else {
                invalid[el.id] = 1;
            }
        } else {
            int max_h = 0;
            while(!pq.empty()) {
                tp = pq.top();
                if(!invalid[tp.second]) {
                    max_h = tp.first;
                    break;
                } else {
                    pq.pop();
                }
            }

            ans[el.id] = (queryHeights[el.id] > max_h);
        }
    }

    for(int i = 0;i < q;i++) {
        if(ans[i]) {
            yes;
        } else {
            no;
        }
    }
}

int main() {
    go();
    solve();
    return 0;
}