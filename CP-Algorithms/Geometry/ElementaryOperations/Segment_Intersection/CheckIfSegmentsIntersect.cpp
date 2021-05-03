#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct pt {
    ll x, y;
    pt() {}
    pt(ll _x, ll _y) :x(_x), y(_y) {}
    pt operator-(const pt &p) const {return pt(x - p.x, y - p.y);}
    ll cross(const pt &p) const {return x * p.y - y * p.x;}
    ll cross(const pt &a, const pt &b) const {return (a - *this).cross(b - *this);}
};

int sgn(const ll &x) {return x >= 0 ? x ? 1 : 0 : -1;}

bool inter1(ll a, ll b, ll c, ll d) {
    if(a > b) swap(a, b);
    if(c > d) swap(c, d);
    return max(a, c) <= min(b, d);
}

bool check_inter(const pt &a, const pt &b, const pt &c, const pt& d) {
    if(c.cross(a, d) == 0 && c.cross(b, d) == 0) {
        return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
    }

    return sgn(a.cross(b, c) != sgn(a.cross(b, d)) && sgn(c.cross(d, a)) != sgn(c.cross(d, b)));
}

int main() {
    pt a(0, 0);
    pt b(1, 1);
    pt c(0, 1);
    pt d(1, 0);

    cout << "Check if segments AB and CD intersects ? " << (check_inter(a, b, c, d) ? "Yes" : "No") << endl;
    return 0;
}
