#include <bits/stdc++.h>

using namespace std;

struct FenwickTree {
  vector<int> bit;
  int n;
  const int INF = (int)1e9;

  FenwickTree(int n) {
    this->n = n;
    bit.assign(this->n, INF);
  }

  FenwickTree(vector<int> a) : FenwickTree(int(a.size())) {
    for(int i = 0;i < int(a.size());i++) {
      update(i, a[i]);
    }
  }

  int getmin(int r) {
    int ret = INF;
    while(r >= 0) {
      ret = min(ret, bit[r]);
      r = (r & (r + 1)) - 1;
    }

    return ret;
  }

  void update(int idx, int val) {
    while(idx < n) {
      bit[idx] = min(bit[idx], val);
      idx = idx | (idx + 1);
    }
  }
};

int main() {
  vector<int> a({3, 2, 1, 2, 3});
  FenwickTree fenwicktree(a);
  cout << "Min from 0 to 3 is : " << fenwicktree.getmin(3) << endl;
  return 0;
}
