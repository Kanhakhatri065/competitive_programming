#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 300000 + 10;
const int SIZE = 4096;
int n, m, u, A[N], block[N / SIZE + 1][SIZE];

void init() {
    cin >> n >> m >> u;
    int b = 0, j = 0;
    for(int i = 0;i < n;i++) {
        cin >> A[i];
        block[b][j]= A[i];
        j++;
        if(j == SIZE) {
            b++;
            j = 0;
        }
    }

    for(int i = 0;i < b;i++) sort(block[i], block[i] + SIZE);
    if(j) sort(block[b], block[b] + j);
}

int query(int L, int R, int v) {
    int lb = L / SIZE, rb = R / SIZE, k = 0;
    if(lb == rb) {
        for(int i = L;i <= R;i++) {
            k += (A[i] < v);
        }
    } else {
        for(int i = L;i < (lb + 1) * SIZE;i++) k += (A[i] < v);
        for(int i = rb * SIZE;i <= R;i++) k += (A[i] < v);
        for(int i = lb + 1;i < rb;i++) k += lower_bound(block[i], block[i] + SIZE, v) - block[i];
    }

    return k;
}

void update(int p, int x) {
    if(A[p] == x) return;
    int old = A[p], pos = 0, *B = &block[p / SIZE][0];
    A[p] = x;
    while(B[pos] < old) pos++;
    B[pos] = x;
    while(pos + 1 < SIZE && B[pos] > B[pos + 1]) {
        swap(B[pos], B[pos + 1]);
        pos++;
    }

    while(pos > 0 && B[pos] < B[pos - 1]) {
        swap(B[pos], B[pos - 1]);
        pos--;
    }
}

int main() {
    init();
    while(m--) {
        int L, R, v, p;
        cin >> L >> R >> v >> p;
        L--, R--, p--;
        int k = query(L, R, v);
        update(p, (long long) u * k / (R - L + 1));
    }

    for(int i = 0;i < n;i++) cout << A[i] << endl;
    return 0;
}
