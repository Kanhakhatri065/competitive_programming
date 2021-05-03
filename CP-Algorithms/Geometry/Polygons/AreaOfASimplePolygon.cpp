#include <bits/stdc++.h>
using namespace std;

struct point {
    double x, y;
};

double area(const vector<point> &fig) {
    double res = 0;
    for(int i = 0;i < int(fig.size());i++) {
        point p = i ? fig[i - 1] : fig.back();
        point q = fig[i];

        res += (p.x - q.x) * (p.y + q.y);
    }

    return fabs(res) / 2.0;
}

int main() {
    vector<point> fig;
    fig.push_back({0, 0});
    fig.push_back({2, 0});
    fig.push_back({0, 2});

    double ans = area(fig);

    cout << "Area of the figure is : " << ans << endl;
    return 0;
}
