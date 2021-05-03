vector<int> prefix_function(const string &s) {
  vector<int> pi(s.size());
  for (int i = 1; i < (int) s.size(); ++i) {
    int p = pi[i - 1];
    while (p > 0 && s[i] != s[p]) p = pi[p - 1];
    if (s[i] == s[p]) pi[i] = 1 + p;
  }
  return pi;
}

auto automata(string s) {
  s += '$';
  auto pi = prefix_function(s);
  vector<array<int,256>> aut(s.size());
  for (int i = 0; i < (int) s.size(); ++i) {
    for (char c = 'a'; c <= 'z'; c++) {
      if (i > 0 && c != s[i]) aut[i][c] = aut[pi[i - 1]][c];
      else aut[i][c] = i + (c == s[i]);
    }
  }
  return aut;
}

vector<int> suffix_array(string s) {
  s += "$";
  const int ALPHA = 256, n = (int) s.size();
  vector<int> suf(n), cls(s.begin(), s.end());
  iota(suf.begin(), suf.end(), 0);
  for (int len = 0, num_cls = ALPHA; len < n; len ? len <<= 1 : ++len) {
    vector<int> suf_aux(n), new_cls(n), radix(num_cls);
    for (int i = 0; i < n; ++i) {
      suf_aux[i] = suf[i] - len;
      if (suf_aux[i] < 0) suf_aux[i] += n;
      radix[cls[suf_aux[i]]]++;
    }
    for (int i = 1; i < num_cls; ++i) radix[i] += radix[i - 1];
    for (int i = n - 1; ~i; --i) suf[--radix[cls[suf_aux[i]]]] = suf_aux[i];
    num_cls = 1; new_cls[suf[0]] = 0;
    for (int i = 1; i < n; ++i) {
      if (cls[suf[i]] != cls[suf[i - 1]] || cls[suf[i] + len] != cls[suf[i - 1] + len]) 
        ++num_cls;
      new_cls[suf[i]] = num_cls - 1;
    }
    cls = std::move(new_cls);
  }
  for (int i = 0; i < n - 1; ++i) suf[i] = suf[i + 1];
  suf.pop_back();
  return suf;
}

// kasai O(n)
vector<int> calc_lcp(const string &s, const vector<int> &suf) {
  const int n = (int) s.size();
  vector<int> rank(n), lcp(n - 1);
  for (int i = 0; i < n; ++i) rank[suf[i]] = i;
  for (int i = 0, k = 0; i < n; ++i, k = max(0, k - 1)) {
    if (rank[i] == n - 1) { k = 0; continue; }
    int j = suf[rank[i] + 1];
    while (i + k < n && j + k < n && s[i + k] == s[j + k]) ++k;
    lcp[rank[i]] = k;
  }
  return lcp;
}

const int MOD = 1e9 + 7;
//please take everything out of the function as it was giving an error while making the template
//that's why I have to put it in a function
void lcp() {
int n;
vector<int> tree(n << 1, MOD);
vector<int> rnks(n);
vector<int> lcp, suf;
for (int i = 0; i < n; ++i) rnks[suf[i]] = i;
for (int i = 0; i < n - 1; ++i) 
  tree[i + n] = lcp[i];
for (int i = n - 1; i > 0; --i) 
  tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
auto ask_lcp = [&] (int L, int R) {
  if (L == R) return n - L;
  L = rnks[L], R = rnks[R];
  if (L > R) swap(L, R);
  int res = n - L;
  for (L += n, R += n; L < R; L /= 2, R /= 2) {
    if (L & 1) res = min(res, tree[L++]);
    if (R & 1) res = min(res, tree[--R]);
  }
  return res;
};
}

inline int add(int a, int b, int mod = MOD) {
  a += b; return a >= mod ? a - mod : a;
}
inline int sub(int a, int b, int mod = MOD) {
  a -= b; return a < 0 ? a + mod : a;
}
inline int mul(int a, int b, int mod = MOD) {
  return int((long long) a * b % mod);
}

inline int mpow(int base, long long ex, int mod = MOD) {
  int res = 1;
  for (; ex > 0; ex >>= 1) {
    if (ex & 1) res = mul(res, base, mod);
    base = mul(base, base, mod);
  }
  return res;
}

inline int inv(int a, int mod = MOD) {
  return mpow(a, mod - 2, mod);
}

struct StringHash {
  static array<int,2> mods;
  static const int base;
  static vector<array<int,2>> base_pows, base_invs;
  vector<array<int,2>> pref;
  StringHash(const string &s): pref(s.size() + 1) {
    for (int i = 0; i < (int) s.size(); ++i) {
      for (int j = 0; j < 2; ++j) {
        pref[i + 1][j] = add(pref[i][j], mul(s[i] - 'a' + 1, base_pows[i][j], mods[j]), mods[j]);
      }
    }
  }
  auto get_hash(int i, int j) {
    array<int,2> res;
    for (int k = 0; k < 2; ++k) {
      res[k] = mul(base_invs[i][k], sub(pref[j + 1][k], pref[i][k], mods[k]), mods[k]);
    }
    return res;
  }
  static void prepare(int n) {
    mods = {(int) 1e9 + 7, (int) 1e9 + 9};
    base_pows.resize(n);
    base_invs.resize(n);
    for (int k = 0; k < 2; ++k) {
      base_pows[0][k] = base_invs[0][k] = 1;
      const int binv = inv(base, mods[k]);
      for (int i = 1; i < n; ++i) {
        base_pows[i][k] = mul(base, base_pows[i - 1][k], mods[k]);
        base_invs[i][k] = mul(binv, base_invs[i - 1][k], mods[k]);
      }
    }
  }
};
array<int,2> StringHash::mods;
const int StringHash::base = 3;
vector<array<int,2>> StringHash::base_pows, StringHash::base_invs;
