#include <bits/stdc++.h>
using namespace std;

const int N = 25;
int n, m;
int a[N][N];
int t[4 * N][4 * N];

void build_y(int nodex, int lx, int rx, int nodey, int ly, int ry) {
    if (ly == ry) {
        if (lx == rx)
            t[nodex][nodey] = a[lx][ly];
        else
            t[nodex][nodey] = t[nodex << 1][nodey] + t[nodex << 1 | 1][nodey];
    } else {
        int my = (ly + ry) / 2;
        build_y(nodex, lx, rx, nodey << 1, ly, my);
        build_y(nodex, lx, rx, nodey << 1 | 1, my+1, ry);
        t[nodex][nodey] = t[nodex][nodey << 1] + t[nodex][nodey << 1 | 1];
    }
}

void build_x(int nodex, int lx, int rx) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        build_x(nodex << 1, lx, mx);
        build_x(nodex << 1 | 1, mx+1, rx);
    }
    build_y(nodex, lx, rx, 1, 0, m-1);
}

int sum_y(int nodex, int nodey, int travly, int travry, int ly, int ry) {
    if (ly > ry) 
        return 0;
    if (ly == travly && travry == ry)
        return t[nodex][nodey];
    int travmy = (travly + travry) / 2;
    return sum_y(nodex, nodey << 1, travly, travmy, ly, min(ry, travmy))
         + sum_y(nodex, nodey << 1 | 1, travmy+1, travry, max(ly, travmy+1), ry);
}

int sum_x(int nodex, int travlx, int travrx, int lx, int rx, int ly, int ry) {
    if (lx > rx)
        return 0;
    if (lx == travlx && travrx == rx)
        return sum_y(nodex, 1, 0, m-1, ly, ry);
    int travmx = (travlx + travrx) / 2;
    return sum_x(nodex << 1, travlx, travmx, lx, min(rx, travmx), ly, ry)
         + sum_x(nodex << 1 | 1, travmx+1, travrx, max(lx, travmx+1), rx, ly, ry);
}

void update_y(int nodex, int lx, int rx, int nodey, int ly, int ry, int x, int y, int new_val) {
    if (ly == ry) {
        if (lx == rx)
            t[nodex][nodey] = new_val;
        else
            t[nodex][nodey] = t[nodex << 1][nodey] + t[nodex << 1 | 1][nodey];
    } else {
        int my = (ly + ry) / 2;
        if (y <= my)
            update_y(nodex, lx, rx, nodey << 1, ly, my, x, y, new_val);
        else
            update_y(nodex, lx, rx, nodey << 1 | 1, my+1, ry, x, y, new_val);
        t[nodex][nodey] = t[nodex][nodey << 1] + t[nodex][nodey << 1 | 1];
    }
}

void update_x(int nodex, int lx, int rx, int x, int y, int new_val) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        if (x <= mx)
            update_x(nodex << 1, lx, mx, x, y, new_val);
        else
            update_x(nodex << 1 | 1, mx+1, rx, x, y, new_val);
    }
    update_y(nodex, lx, rx, 1, 0, m-1, x, y, new_val);
}

int main() {
    cout << "Enter dimensions of the array : " << endl;
    cin >> n >> m;

    cout << "Enter array elements : " << endl;
    for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) cin >> a[i][j];

    cout << "Build initiated" << endl;
    memset(t, 0, sizeof(t));
    build_x(1, 0, n - 1);
    cout << "Build completed" << endl;

    cout << "Enter number of queries : " << endl;
    int q;cin >> q;
    while(q--) {
        cout << "Enter type of query :\n1. Sum\n2. Update" << endl;
        int type;cin >> type;
        if(type == 1) {
            cout << "Enter ranges x1 to x2 and y1 to y2 : " << endl;
            int x1, x2, y1, y2;cin >> x1 >> x2 >> y1 >> y2;
            int ans = sum_x(1, 0, n - 1, x1, x2, y1, y2);
            cout << "Sum in the given submatrix : " << ans << endl;
        } else {
            cout << "Enter x and y index and new value : " << endl;
            int x, y, new_val;cin >> x >> y >> new_val;
            
            cout << "Update initiated" << endl;
            update_x(1, 0, n  - 1, x, y, new_val);
            cout << "Update completed" << endl;
        }
    }
    return 0;
}