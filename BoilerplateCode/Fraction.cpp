struct frac {
  typedef __int128 mul_t;
  int64_t num, den;
  frac(int64_t x = 0, int64_t y = 1) {
    if (x == 0 || y == 0) {
      //~ assert (x || y);
      if (x < 0) {
        num = -1, den = 0; // change to num = 1 if sign dont matter for oo
      } else if (x > 0) {
        num = 1, den = 0;
      } else {
        num = 0, den = 1;
      }
      return;
    }
    if (y < 0) {
      x = -x; y = -y;
    }
    num = x, den = y;
    norm();
  }
  inline void norm() {
    int64_t g = __gcd(abs(num), abs(den));
    num /= g;
    den /= g;
  }
  bool operator < (const frac &rhs) const {
    return (mul_t) num * rhs.den < (mul_t) rhs.num * den;
  }
  bool operator > (const frac &rhs) const {
    return (mul_t) num * rhs.den > (mul_t) rhs.num * den;
  }
  bool operator == (const frac &rhs) const {
    return (mul_t) num * rhs.den == (mul_t) rhs.num * den;
    //~ if (num == 0) return rhs.num == 0;
    //~ if (den == 0) return rhs.den == 0;
    //~ return num == rhs.num && den == rhs.den;
  }
  frac operator + (const frac &rhs) const {
    return frac(num * rhs.den + rhs.num * den, den * rhs.den);
  }
  frac operator - (const frac &rhs) const {
    return frac(num * rhs.den - rhs.num * den, den * rhs.den);
  }
  frac operator * (const frac &rhs) const {
    return frac(num * rhs.num, den * rhs.den);
  }
  frac operator / (const frac &rhs) const {
    return frac(num * rhs.den, den * rhs.num);
  }
  static frac zero() {
    return frac(0, 1);
  }
  static frac inf() {
    return frac(1, 0);
  }
  friend string to_string(const frac &f) {
    string res = to_string(f.num);
    res += "/";
    res += to_string(f.den);
    return res; 
  }
};