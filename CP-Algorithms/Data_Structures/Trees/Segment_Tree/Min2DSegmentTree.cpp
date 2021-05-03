#include <bits/stdc++.h>

using namespace std;

const int N = 50;
int a[N][N], t[4 * N][4 * N];
int n, m;

void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
    if(ly == ry) {
        if(lx == rx) {
            t[vx][vy] = a[lx][ly];
        } else {
            t[vx][vy] = min(t[vx << 1][vy], t[vx << 1 | 1][vy]);
        }
    } else {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy << 1, ly, my);
        build_y(vx, lx, rx, vy << 1 | 1, my + 1, ry);
        t[vx][vy] = min(t[vx][vy << 1], t[vx][vy << 1 | 1]);
    }
}

void build_x(int vx, int lx, int rx) {
    if(lx != rx) {
        int mx = (lx + rx) / 2;
        build_x(vx << 1, lx, mx);
        build_x(vx << 1 | 1, mx + 1, rx);
    }

    build_y(vx, lx, rx, 1, 0, m - 1);
}

int query_y(int vx, int vy, int tly, int try_, int ly, int ry) {
    if(ly > ry) return INT_MAX;
    if(ly == tly && ry == try_) {
        return t[vx][vy];
    }

    int tmy = (tly + try_) >> 1;
    return min(query_y(vx, vy << 1, tly, tmy, ly, min(ry, tmy)), query_y(vx, vy << 1 | 1, tmy + 1, try_, max(ly, tmy + 1), ry));
}

int query_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if(lx > rx) INT_MAX;
    if(lx == tlx && rx == trx) {
        return query_y(vx, 1, 0, m - 1, ly, ry);
    }

    int tmx = (tlx + trx) >> 1;
    return min(query_x(vx << 1, tlx, tmx, lx, min(rx, tmx), ly, ry), query_x(vx << 1 | 1, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry));
}

void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
    if(ly == ry) {
        if(lx == rx) {
            t[vx][vy] = new_val;
        } else {
            t[vx][vy] = min(t[vx << 1][vy], t[vx << 1 | 1][vy]);
        }
    } else {
        int my = (ly + ry) >> 1;
        if(y <= my) {
            update_y(vx, lx, rx, vy << 1, ly, my, x, y, new_val);
        } else {
            update_y(vx, lx, rx, vy << 1 | 1, my + 1, ry, x, y, new_val);
        }

        t[vx][vy] = min(t[vx][vy << 1], t[vx][vy << 1 | 1]);
    }
}

void update_x(int vx, int lx, int rx, int x, int y, int new_val) {
    if(lx != rx) {
        int mx = (lx + rx) >> 1;
        if(x <= mx) {
            update_x(vx << 1, lx, mx, x, y, new_val);
        } else {
            update_x(vx << 1 | 1, mx + 1, rx, x, y, new_val);
        }
    }

    update_y(vx, lx, rx, 1, 0, m - 1, x, y, new_val);
}

int main() {
    cin >> n >> m;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin >> a[i][j];
        }
    }

    cout << "From (0, 0) to (1, 1) min : " << query_x(1, 0, n - 1, 0, 0, 1, 1) << endl;
    cout << "Change (1, 1) to 1 : " << endl;
    update_x(1, 0, n - 1, 1, 1, 1);

    cout << "From (0, 1) to (2, 2) min : " << query_x(1, 0, n - 1, 0, 1, 2, 2) << endl;
    return 0;
}
