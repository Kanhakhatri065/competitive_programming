#include <bits/stdc++.h>
using namespace std;

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
