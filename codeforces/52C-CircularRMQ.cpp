#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 2e5 + 5;
const ll INF = 1e18;

struct node
{
    ll val, lazy;
    struct node *left;
    struct node *right;
    node() : val(0), lazy(0), left(NULL), right(NULL){};
};
 
void update(node* n, int start, int end, int l, int r, int val)
{
    if(n->left == NULL) n->left = new node();
    if(n->right == NULL) n->right = new node();
 
    if(n->lazy != 0)
    {
        ll dx = n->lazy;
        n->lazy = 0;
        n->val += dx;
 
		if(start != end)
            n->left->lazy += dx, n->right->lazy += dx;
    }
 
    if(r < start or end < l) return;
    if(l <= start and end <= r)
    {
        n->val += val;
        if(start != end)
        {
            n->left->lazy += val;
            n->right->lazy += val;
        }
        return;
    }
 
    int mid = (start + end)/2;
    update(n->left, start, mid, l, r, val);
    update(n->right, mid+1, end, l, r, val);
    n->val = min(n->left->val, n->right->val);
    return;
}
 
ll query(node* n, int start, int end, int l, int r)
{
    if(n == NULL or r < start or end < l) return 1e18;
 
    if(n->lazy != 0)
    {
        ll dx = n->lazy;
        n->lazy = 0;
        n->val += dx;
 
		if(start != end) n->left->lazy += dx, n->right->lazy += dx;
    }
 
    if(l <= start and end <= r) return n->val;
    int mid = (start + end)/2;
    ll p1 = query(n->left, start, mid, l, r);
    ll p2 = query(n->right, mid+1, end, l, r);
    return min(p1, p2);
}
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin>>n;
    node* root = new node();
    for(int i = 0;i < n;i++) {
        int x;
        cin >> x;
        update(root, 0, n-1, i, i, x);
    }

    int q;
    cin>>q;
    string s;
    getline(cin,s);
    while(q--)
    {
        string s;
        getline(cin,s);
        stringstream ss(s);
        int a,b;
        ll c;
        ss>>a>>b;
        if(ss>>c)
        {
            if(a>b) {update(root,0,n-1,0,b,c);update(root,0,n-1,a,n-1,c);}
            else update(root,0,n-1,a,b,c);
        }
        else
        {
            if(a>b) cout<<min(query(root,0,n-1,0,b),query(root,0,n-1,a,n-1))<<'\n';
            else cout<<query(root,0,n-1,a,b)<<'\n';
        }
    }
 
    return 0;
}
