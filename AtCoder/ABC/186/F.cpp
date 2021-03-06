/*
    I love the sound you make when you shut up.
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
/*----typedefs--------*/
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
using ll = long long;
using pi = pair<int, int>;
/*-----in and out--------*/
#define pf(a) cout << a << endl
#define forIn(arr, num) for(int i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(int i = 0; i < int(ans.size()); i++) cout << ans[i] << (i + 1 < int(ans.size()) ? ' ' : '\n');
/*---useful defines------*/
#define sz(x) (int)(x).size()
#define pb push_back
#define mem(a, b) memset(a,(b), sizeof(a))
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
/*----- the binary answer of life-----*/
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
/*---checking and pushing-----*/
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
/*---- FAST I/O and file read ---*/
void go() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
}
/*-------- movement in a 2D array ------*/
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
/*--------test-case stuff---------------*/
#define ssolve solve();
#define msolve int t;cin >> t;while(t--) {solve();}
#define mcsolve int t;cin >> t;for(int tt = 1;tt <= t;tt++) {cout << "Case #" << tt << ": ";solve();}
/*----------------------------------------------------------------*/
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
/*-------------- Push your limits here ---------------------------*/
int n, m, k;
int cnt[N];
void add(int x)
{
	for(int i=x;i<=m;i+=(i&(-i))){
		++cnt[i];
	}
}
int ask(int x)
{
	int ret=0;
	for(int i=x;i>0;i-=(i&(-i))){
		ret+=cnt[i];
	}
	return ret;
}

void solve() {
    cin>>n>>m>>k;
	vector<int> a(n+1),b(m+1);
	for(int i = 1;i <= n;i++) a[i]=m;
	for(int i = 1;i <= m;i++) b[i]=n;
	
    if(!k){
		cout<<1ll*n*m<<endl;
		return;
	}

	for(int i = 0;i < k;i++) {
		int x,y;
		cin>>x>>y;
		a[x]=min(a[x],y-1);
		b[y]=min(b[y],x-1);
	}

	ll ans=0;
	for(int i = 1;i <= b[1];i++) ans+=a[i];
	
    vector<int> pos(a[1]+1);
	for(int i = 1;i <= a[1];i++) pos[i]=i;
	
    sort(pos.begin()+1,pos.end(),[&](int x,int y){
		return b[x]<b[y];
	});
	
    for(int i = 1;i <= a[1];i++) {
		int r=pos[i],l=pos[i-1];
		for(int j=b[l]+1;j<=b[r]&&j<=b[1];j++){
			add(a[j]);
		}
		ans+=b[r]+ask(r-1)-ask(m);
	}

	pf(ans);
}

int main() {
    //go();
    ssolve
    return 0;
}
