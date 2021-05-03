#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

int main() {
    //we are taking circle at origin but if you take another center translate it to origin
    //equation of line ax + by + c = 0
    double r, a, b, c;
    cin >> r >> a >> b >> c;
    double x0 = -a*c /(a * a + b * b), y0 = -b*c / (a * a + b * b);
    if(c * c > (r * r * (a * a + b * b)) + EPS) {
        cout << "No points" << endl;
    } else if(abs(c * c - r * r * (a * a + b * b)) < EPS) {
        cout << "1 point" << endl;
        cout << x0 << " " << y0 << endl;
    } else {
        double d = r * r - c * c / (a * a + b * b);
        double mult = sqrt(d / (a * a + b * b));
        double ax, ay, bx, by;
        ax = x0 + b * mult;
        bx = x0 - b * mult;
        ay = y0 - a * mult;
        by = y0 + a  * mult;

        cout << "2 points" << endl;
        cout << ax << " " << ay << endl;
        cout << bx << " " << by << endl;
    }

    return 0;
}
