#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

struct node {
    int val;
    node *left;
    node *right;
    node() {}
    node(node *l, node *r, int v) {
        left = l;
        right = r;
        val = v;
    }
};

int arr[MAX];
node* version[MAX];

void build(node* n, int low, int high) {
    if(low == high) {
        n->val = arr[low];
        return;
    }

    int mid = (low + high) >> 1;
    n->left = new node(NULL, NULL, 0);
    n->right = new node(NULL, NULL, 0);
    build(n->left, low, mid);
    build(n->right, mid + 1, high);
    n->val = n->left->val + n->right->val;
}

void update(node* prev, node* cur, int low, int high, int idx, int value) {
    if(idx > high || idx < low || low > high) return;

    if(low == high) {
        cur->val = value;
        return;
    }

    int mid = (low + high) >> 1;
    if(idx <= mid) {
        cur->right = prev->right;
        cur->left = new node(NULL, NULL, 0);
        update(prev->left, cur->left, low, mid, idx, value);
    } else {
        cur->left = prev->left;
        cur->right = new node(NULL, NULL, 0);
        update(prev->right, cur->right, mid + 1, high, idx, value);
    }

    cur->val = cur->left->val + cur->right->val;
}

int query(node* n, int low, int high, int l, int r) {
    if(l > high || r < low || low > high) return 0;

    if(l <=  low && high <= r) {
        return n->val;
    }

    int mid = (low + high) >> 1;
    int p1 = query(n->left, low, mid, l, r);
    int p2 = query(n->right, mid + 1, high, l, r);
    return p1 + p2;
}

int main() {
    int n = 5;
    for(int i = 0;i < n;i++) cin >> arr[i];

    node* root = new node(NULL, NULL, 0);
    build(root, 0, n - 1);

    version[0] = root;

    version[1] = new node(NULL, NULL, 0);
    cout << "In version 1 change element at idx 4 to 1" << endl;
    update(version[0], version[1], 0, n-1, 4, 1);
  
    // upgrading to version-2
    version[2] = new node(NULL, NULL, 0);
    cout << "In version 2 change element at idx 2 to 10" << endl;
    update(version[1],version[2], 0, n-1, 2, 10);
  
    cout << "In version 1 , query(0,4) : ";
    cout << query(version[1], 0, n-1, 0, 4) << endl;
  
    cout << "In version 2 , query(3,4) : ";
    cout << query(version[2], 0, n-1, 3, 4) << endl;
  
    cout << "In version 0 , query(0,3) : ";
    cout << query(version[0], 0, n-1, 0, 3) << endl; 
    
    return 0;
}


