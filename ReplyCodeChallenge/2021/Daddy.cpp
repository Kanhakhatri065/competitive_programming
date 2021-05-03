#include <bits/stdc++.h>
using namespace std;

#define pf(a) cout << a << endl
#define forIn(arr, num) for(int i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(int i = 0; i < int(ans.size()); i++) cout << ans[i] << (i + 1 < int(ans.size()) ? ' ' : '\n');

#define sz(x) (int)(x).size()
#define pb push_back
#define mem(a, b) memset(a,(b), sizeof(a))
#define ff first
#define ss second
#define all(x) x.begin(), x.end()

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define int long long
using pi = pair<int, int>;
void go() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("c.txt", "r", stdin);
    freopen("c_out.txt", "w", stdout);
#endif
}

struct Building {
    int x, y, l, c;
    Building(int _x, int _y, int _l, int _c) {
        x = _x;
        y = _y;
        l = _l;
        c = _c;
    }
};

struct Antenna {
    int id, r, c;
    Antenna(int _id, int _r, int _c) {
        id = _id;
        r = _r;
        c = _c;
    }
};


int manhattan_distance(Building a, Building b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

vector<Building> buildings;
vector<Antenna> towers;
int w, h;
int n, m, r;
void solve() {
    cin >> h >> w;
    cin >> n >> m >> r;

    for(int i = 0;i < n;i++) {
        int x, y, l, c;
        cin >> x >> y >> l >> c;
        buildings.push_back(Building(x, y, l, c));
    }


    for(int i = 0;i < m;i++) {
        int ra, cc;
        cin >> ra >> cc;
        towers.push_back(Antenna(i, ra, cc));
    }

    sort(all(towers), [&](auto a, auto b) {
        if(a.c == b.c) {
            return a.r > b.r;
        }

        return a.c > b.c;
    });

    pi grid[h][w];
    for(int i = 0;i < h;i++) for(int j = 0;j < w;j++) {
        grid[h][w].ff = INT_MAX;
        grid[h][w].ss = 0;
    }

    for(int i = 0;i < n;i++) {
        int x = buildings[i].x, y = buildings[i].y;
        int l = buildings[i].l, c = buildings[i].c;

        for(int j = -l;j <= l;j++) {
            for(int k = -l;k <= l;k++) {
                int p = x + j;
                int q = y + k;

                if(p >= 0 && p < h && q >= 0 && q < w) {
                    ckmin(grid[p][q].ff, l);
                    ckmax(grid[p][q].ss, c);
                }
            }
        }
    }    

    priority_queue<pair<pi, pi>> pq;
    for(int i = 0;i < h;i++) {
        for(int j = 0;j < w;j++) {
            pq.push({grid[i][j], {i, j}});
        }
    }

    vector<pair<int, pi>> ans;
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    for(int i = 0;i < m;i++) {
        int id = towers[i].id;
        int range = towers[i].r;

        int x = -1, y = -1;
        while(!pq.empty()) {
            x = pq.top().ss.ff, y = pq.top().ss.ss;
            pq.pop();
            if(!visited[x][y]) {
                break;
            }
        }

        if(x < 0 || x >= h || y < 0 || y >= w) {
            break;
        }

        ans.pb({id, {x, y}});

        for(int j = -range;j <= range;j++) {
            for(int k = -range;k <= range;k++) {
                int p = x + j, q = y + k;
                if(p >= 0 && p < h && q >= 0 && q < w) {
                    visited[p][q] = true;
                }
            }
        }

    }

    pf(sz(ans));
    for(auto it : ans) {
        cout << it.ff << " " << it.ss.ff << " " << it.ss.ss << endl;
    }
}   

int32_t main() {
    go();
    solve();
    return 0;
}
