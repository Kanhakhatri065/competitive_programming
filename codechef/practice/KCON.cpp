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
ll kadane(int arr[], int n) {
    ll currSum = 0LL, maxSum = INT_MIN;
    for(int i = 0;i < n;i++) {
        currSum += arr[i];
        maxSum = max(maxSum, currSum);
        if(currSum < 0) {
            currSum = 0;
        }
    }

    return maxSum;
}

ll maxSubarraySum(int arr[], int n, int k) {
    ll kadanes_sum = kadane(arr, n);
    if(k == 1) {
        return kadanes_sum;
    }

    ll currPrefixSum = 0LL, currSuffixSum = 0LL;
    ll maxPrefixSum = INT_MIN, maxSuffixSum = INT_MIN;
    for(int i = 0;i < n;i++) {
        currPrefixSum += arr[i];
        maxPrefixSum = max(maxPrefixSum, currPrefixSum);
    }

    ll totalSum = currPrefixSum;
    for(int i = n - 1;i >= 0;i--) {
        currSuffixSum += arr[i];
        maxSuffixSum = max(maxSuffixSum, currSuffixSum);
    }

    ll ans = 0;
    if(totalSum < 0) {
        ans = max(maxSuffixSum + maxPrefixSum, kadanes_sum);
    } else {
        ans = max(maxPrefixSum + maxSuffixSum + (k - 2) * totalSum, kadanes_sum);
    }

    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;

    int arr[n];
    for(int i = 0;i < n;i++) {
        sc(arr[i]);
    }

    ll ans = maxSubarraySum(arr, n, k);
    pf(ans);
}

int main() {
    FAST_IO
    int t;
    sc(t);

    while(t--) {
        solve();
    }

    return 0;
}