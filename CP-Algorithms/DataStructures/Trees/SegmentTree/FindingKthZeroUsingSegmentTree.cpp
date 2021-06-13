#include <bits/stdc++.h>
using namespace std;

const int N = 25;
int t[4 * N];
int n;
vector<int> a;
void build(int node, int tl, int tr) {
    if(tl == tr) {
        if(a[tl] == 0) {
            t[node] = 1;
        } else {
            t[node] = 0;
        }
        return;
    }

    int tm = (tl + tr) >> 1;
    build(node << 1, tl, tm);
    build(node << 1 | 1, tm + 1, tr);
    t[node] = t[node << 1] + t[node << 1 | 1];
}

void update(int node, int tl, int tr, int idx, int new_val) {
    if(tl == tr) {
        if(new_val == 0) {
            t[node] = 1;
        } else {
            t[node] = 0;
        }
        return;
    }

    int tm = (tl + tr) >> 1;
    if(idx <= tm) {
        update(node << 1, tl, tm, idx, new_val);
    } else {
        update(node << 1 | 1, tm + 1, tr, idx, new_val);
    }

    t[node] = t[node << 1] + t[node << 1 | 1];
}

int count_zeros(int node, int tl, int tr, int l, int r) {
    if(l > r) return 0;
    if(l == tl && r == tr) {
        return t[node];
    }
    
    int tm = (tl + tr) >> 1;
    return count_zeros(node << 1, tl, tm, l, min(r, tm)) + 
        count_zeros(node << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
}

int find_kth(int node, int tl, int tr, int k) {
    if(k > t[node]) return -1;

    if(tl == tr) return tl;

    int tm = (tl + tr) >> 1;
    if(t[node << 1] >= k) {
         return find_kth(node << 1, tl, tm, k);
    } 
    
    return find_kth(node << 1 | 1, tm + 1, tr, k - t[node << 1]);
}

int main() {
    cout << "Enter array size" << endl;
    cin >> n;
    a.resize(n);

    cout << "Enter array elements" << endl;
    for(int i = 0;i < n;i++) cin >> a[i];

    cout << "Build Initiated" << endl;
    build(1, 0, n - 1);
    cout << "Build completed" << endl;

    cout << "Enter number of queries" << endl;
    int q;cin >> q;
    while(q--) {
        cout << "Enter type of query:\n1.Count Zeros In Range" << endl;
        cout << "2.Find Kth-Zero\n3.Update" << endl;
        int type;cin >> type;
        if(type == 1) {
            cout << "enter range" << endl;
            int l, r;cin >> l >> r;
            int ans = count_zeros(1, 0, n - 1, l, r);
            cout << "Number of zeros in the range(" << l << ", " << r << ") : " << ans << endl;
        } else if(type == 2) {
            cout << "Enter k to find the index of kth-zero" << endl;
            int k;cin >> k;
            int idx = find_kth(1, 0, n - 1, k);

            if(idx == -1) {
                cout << "The array contains less than " << k << " zeros" << endl;
            } else {
                cout << "Index of the " << k << "th zero is : " << idx << endl;
            }
        }
    }
    return 0;
}
