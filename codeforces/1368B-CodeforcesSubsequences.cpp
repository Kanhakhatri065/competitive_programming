/*** I came, I saw, I conquered. ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef unsigned long long ull;
#define sc(a) cin >> a
#define pf(a) cout << a << endl
#define forIn(arr, num) for(ll i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
#define mod 1000000007
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
void go() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
/*----------------------------------------------------------------*/
void printt(char ch,long long int times)
{
    for(int i=0;i<times;i++)
    {
        cout<<ch;
    }
}
 
void solve() {
    ll k;
    cin>>k;
 
    ll ar[10]={0};
    for(ll i=0;i<10;i++)
        ar[i]=1;
    ll cur=1,idx=0;
 
    while(cur<k)
    {
        cur/=ar[idx];
        ar[idx]++;
        cur*=ar[idx];
        idx=(idx+1)%10;
    }

    printt('c',ar[0]);
    printt('o',ar[1]);
    printt('d',ar[2]);
    printt('e',ar[3]);
    printt('f',ar[4]);
    printt('o',ar[5]);
    printt('r',ar[6]);
    printt('c',ar[7]);
    printt('e',ar[8]);
    printt('s',ar[9]);
 
    return ;
}

int main() {
    go();
    solve();
    return 0;
}