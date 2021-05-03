const int64_t INF = 1e9;
int n;
vector<int64_t> tree(n << 1, -INF);
auto put = [] (int pos, int64_t val) {
  for (tree[pos += n] = val; pos > 1; pos /= 2) {
    tree[pos >> 1] = max(tree[pos], tree[pos ^ 1]);
  }
};
// [L, R)
auto ask = [] (int L, int R) {
  int64_t res = -INF;
  for (L += n, R += n; L < R; L /= 2, R /= 2) {
      if (L & 1) {
          if(res < tree[L]) {
              res = tree[L];
              
          }
          L++;
      }    

      if (R & 1) {
          R--;
          if(res < tree[R]) {
              res = tree[R];
          }
      }
    }
  return res;
};
