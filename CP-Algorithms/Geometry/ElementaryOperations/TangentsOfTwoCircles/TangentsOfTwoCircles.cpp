#include <bits/stdc++.h>
using namespace std;

struct pt {
    double x, y;
    pt operator-(pt p) {
        pt res = {x - p.x, y - p.y};
        return res;
    }
};

struct circle : pt {
    double r;
};

struct line {
    double a, b, c;
};

const double EPS = 1e-9;
double sqr(double a) {
    return a * a;
}

void tangents(pt c, double r1, double r2, vector<line> &ans) {
    double r = r2 - r1;
    double z = sqr(c.x) + sqr(c.y);
    double d = z - sqr(r);
    if(d < -EPS) return;
    d = sqrt(abs(d));
    line l;
    l.a = (c.x * r + c.y * d) / z;
    l.b = (c.y * r - c.x * d) / z;
    l.c = r1; 
    ans.push_back(l);
}

vector<line> tangents(circle a, circle b) {
    vector<line> ans;
    for(int i = -1;i <= 1;i += 2) {
        for(int j = -1;j <= 1;j += 2) {
            tangents(b - a, a.r * i, b.r * j, ans);
        }
    }

    for(int i = 0;i < int(ans.size());i++) {
        ans[i].c -= ans[i].a * a.x + ans[i].b * a.y;
    }

    return ans;
}

int main() {
    double x1, y1, r1;
    cout << "Coordinates and radius of first circle : " << endl;
    cin >> x1 >> y1 >> r1;
    circle c1;
    c1.x = x1, c1.y = y1, c1.r = r1;

    double x2, y2, r2;
    cout << "Coordinates and radius of second circle : " << endl;
    cin >> x2 >> y2 >> r2;
    circle c2;
    c2.x = x2, c2.y = y2, c2.r = r2;

    vector<line> t = tangents(c1, c2);
    for(auto it : t) {
        cout << it.a << " " << it.b << " " << it.c << endl;
    }

    return 0;
}
