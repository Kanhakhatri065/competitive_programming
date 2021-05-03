#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

int main() {
    double x1, y1, r1;
    cout << "Enter the coordinates of center and the radius of first circle : " << endl;
    cin >> x1 >> y1 >> r1;

    double x2, y2, r2;
    cout << "Enter the coordinates of center and the radius of second circle : " << endl;
    cin >> x2 >> y2 >> r2;

    if(x1 == x2 && y1 == y2) {
        if(r1 == r2) {
            cout << "Infintely Many Intersection points" << endl;
        } else {
            cout << "No points of intersection" << endl;
        }
        return 0;
    }

    double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if(d > r1 + r2) {
        cout << "No points" << endl;
        return 0;
    }

    double a = (r1 * r1 - r2 * r2 + d * d) / (2 * d);
    double h = sqrt(r1 * r1 - a * a);
    double x3 = x1 + a * (x2 - x1) / d, y3 = y1 + a * (y2 - y1) / d;
    double x4 = x3 + h * (y2 - y1) / d, y4 = y3 - h * (x2 - x1) / d;
    double x5 = x3 - h * (y2 - y1) / d, y5 = y3 + h * (x2 - x1) / d;

    if(x4 == x5 && y4 == y5) {
        cout << "1 points" << endl;
        cout << x4 << " " << y4 << endl;
    } else {
        cout << "2 points" << endl;
        cout << x4 << " " << y4 << endl;
        cout << x5 << " " << y5 << endl;
    }

    return 0;
}
