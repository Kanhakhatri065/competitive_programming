#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct point3D {
    T x, y, z;
    point3D() {}
    point3D(T x, T y, T z): x(x), y(y), z(z) {}
    point3D& operator+=(const point3D<T> &t) {
        x += t.x;
        y += t.y;
        z += t.z;
        return *this;
    }
    point3D& operator-=(const point3D<T> &t) {
        x -= t.x;
        y -= t.y;
        z -= t.z;
        return *this;
    }
    point3D& operator*=(T t) {
        x *= t;
        y *= t;
        z *= t;
        return *this;
    }
    point3D& operator/=(T t) {
        x /= t;
        y /= t;
        z /= t;
        return *this;
    }
    point3D operator+(const point3D<T> &t) const {
        return point3D<T>(*this) += t;
    }
    point3D operator-(const point3D<T> &t) const {
        return point3D<T>(*this) -= t;
    }
    point3D operator*(T t) const {
        return point3D<T>(*this) *= t;
    }
    point3D operator/(T t) const {
        return point3D<T>(*this) /= t;
    }
};

template <typename T> point3D<T> operator*(T a, point3D<T> b) {
    return b * a;
}

template <typename T> T dot(point3D<T> a, point3D<T> b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
} 

template <typename T> point3D<T> cross(point3D<T> a, point3D<T> b) {
    return point3D<T>(a.y * b.z - a.z * b.y,
                   a.z * b.x - a.x * b.z,
                   a.x * b.y - a.y * b.x);
}

template <typename T> T triple(point3D<T> a, point3D<T> b, point3D<T> c) {
    return dot(a, cross(b, c));
}

template <typename T> point3D<T> intersect(point3D<T> a1, point3D<T> n1, point3D<T> a2, point3D<T> n2, point3D<T> a3, point3D<T> n3) {
    point3D<T> x(n1.x, n2.x, n3.x);
    point3D<T> y(n1.y, n2.y, n3.y);
    point3D<T> z(n1.z, n2.z, n3.z); 
    point3D<T> d(dot(a1, n1), dot(a2, n2), dot(a3, n3));
    return point3D<T>(triple(d, y, z), triple(x, d, z), triple(x, y, d)) / triple(n1, n2, n3);
}