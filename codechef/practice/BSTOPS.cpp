/*** I came, I saw, I conquered. ***/
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;typedef unsigned long long ull;
/*** Input Output ***/
#define sc(a) cin >> a
#define pf(a) cout << a << endl
/*** Loops ***/
#define f(i, p, num) for(ll i = p; i < num; i++)
#define forIn(arr, num) for(ll i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
/*** Define Values ***/
#define mod1 1000000007
#define mod2 998244353
#define eps 1e-7
/*** Abbrevations **/
#define pb push_back
#define ff first
#define ss second
#define mem(name, value) memset(name, value, sizeof(name))
/*** STLs ***/
typedef vector<ll>vll;typedef set<ll>sll;typedef multiset<ll>msll;
typedef map<ll,ll>mll;typedef pair<ll,ll>pll;
/*** Sorts ***/
#define all(v) (v).begin(), (v).end()
#define srt(v) sort(all(v))
/*** Bit-Stuff ***/
#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
/*** Some Prints ***/
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
/*----------------------------------------------------------------*/
struct Node {
    ll value, val;
    Node *left, *right;
};

Node* newNode(ll x, ll val) {
    Node* temp = new Node;
    temp->value = x;
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node* insert(Node* node, ll x, ll val) {
    if(node == NULL) {
        return newNode(x, val);
    } else if(x < node->value) {
        node->left = insert(node->left, x, 2 * val);
    } else {
        node->right = insert(node->right, x, 2 * val + 1);
    }

    return node;
}

Node* minValue(Node* node) {
    Node* current = node;
    while(current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

Node* delet(Node* node, ll x) {
    if(node == NULL) {
        return node;
    }

    if(x < node->value) {
        node->left = delet(node->left, x);
    } else if(x > node->value) {
        node->right = delet(node->right, x);
    } else {
        if(node->left == NULL) {
            Node* temp = node->right;
            delete(node);
            return temp;
        } else if(node->right == NULL) {
            Node* temp = node->left;
            delete(node);
            return temp;
        }
        Node* temp = minValue(node->right);
        node->value = temp->value;
        node->right = delet(node->right, temp->value);
    }

    return node;
}

ll find(ll data, Node* node) {
    if(node->value == data) {
        return node->val;
    } else if(data < node->value) {
        return find(data, node->left);
    }

    return find(data, node->right);
}

void solve() {
    Node* root = NULL;
    int q;
    sc(q);

    char type;
    int x;
    while(q--) {
        cin >> type >> x;
        if(type == 'i') {
            root = insert(root, x, 1);
            pf(find(x, root));
        } else {
            pf(find(x, root));
            root = delet(root, x);
        }
    }
}

int main() {
    FAST_IO
    solve();
    return 0;
}