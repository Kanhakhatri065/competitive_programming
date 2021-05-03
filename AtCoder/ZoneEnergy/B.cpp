#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pf(a) cout << a << endl
#define forIn(arr, num) for(int i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(auto it : ans) {cout << it << " ";}cout << endl;
#define sz(x) (int)(x).size()
#define pb push_back
#define mem(a, b) memset(a,(b), sizeof(a))
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
void go() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
}
#define ssolve solve();
#define msolve int T;cin >> T;while(T--) {solve();}
#define mcsolve int T;cin >> T;for(int tt = 1;tt <= T;tt++) {cout << "Case #" << tt << ": ";solve();}
string to_string(string s) {
  return '"' + s + '"';
}
string to_string(const char* s) {
  return to_string((string) s);
}
string to_string(bool b) {
  return (b ? "true" : "false");
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

template <typename T>
struct point2D {
    T x, y;
    point2D() {}
    point2D(T x, T y): x(x), y(y) {}
    point2D& operator+=(const point2D &t) {
        x += t.x;
        y += t.y;
        return *this;
    }
    point2D& operator-=(const point2D &t) {
        x -= t.x;
        y -= t.y;
        return *this;
    }
    point2D& operator*=(T t) {
        x *= t;
        y *= t;
        return *this;
    }
    point2D& operator/=(T t) {
        x /= t;
        y /= t;
        return *this;
    }
    point2D operator+(const point2D &t) const {
        return point2D(*this) += t;
    }
    point2D operator-(const point2D &t) const {
        return point2D(*this) -= t;
    }
    point2D operator*(T t) const {
        return point2D(*this) *= t;
    }
    point2D operator/(T t) const {
        return point2D(*this) /= t;
    }
};

template <typename T> point2D<T> operator*(T a, point2D<T> b) {
    return b * a;
}

template <typename T> T dot(point2D<T> a, point2D<T> b) {
    return a.x * b.x + a.y * b.y;
} 

template <typename T> T norm(point2D<T> a) {
    return dot(a, a);
}

template <typename T> double abs(point2D<T> a) {
    return sqrt(norm(a));
}

template <typename T> double proj(point2D<T> a, point2D<T> b) {
    return dot(a, b) / abs(b);
}

template <typename T> double angle(point2D<T> a, point2D<T> b) {
    return acos(dot(a, b) / abs(a) / abs(b));
}

template <typename T> T cross(point2D<T> a, point2D<T> b) {
    return a.x * b.y - a.y * b.x;
}

template <typename T> point2D<T> intersect(point2D<T> a1, point2D<T> d1, point2D<T> a2, point2D<T> d2) {
    return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d1;
}

template<typename T> int signed_area_parallelogram(point2D<T> p1, point2D<T> p2, point2D<T> p3) {
    return cross(p2 - p1, p3 - p2);
}

template<typename T> double triangle_area(point2D<T> p1, point2D<T> p2, point2D<T> p3) {
    return abs(signed_area_parallelogram(p1, p2, p3)) / 2.0;
}

template<typename T> bool clockwise(point2D<T> p1, point2D<T> p2, point2D<T> p3) {
    return signed_area_parallelogram(p1, p2, p3) < 0;
}

template<typename T> bool counter_clockwise(point2D<T> p1, point2D<T> p2, point2D<T> p3) {
    return signed_area_parallelogram(p1, p2, p3) > 0;
}

void solve() {
    int n, d, h;
    cin >> n >> d >> h;

    point2D<double> ufo(d, h);
    double ans = 0.0;

    for(int i = 0;i < n;i++) {
        int x, y;
        cin >> x >> y;
        point2D<double> p(x, y);
        double slope = (ufo.y - p.y) / (ufo.x - p.x);
        double c = p.y - slope * p.x;
        ckmax(ans, c);
    }

    cout << fixed << setprecision(10) << ans << endl;
}

int main() {
    go();
    ssolve
    return 0;
}
