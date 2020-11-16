#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
const int INF=0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: (a))
#define SZ(x) ((int)(x).size())
#define PB push_back
#define X first
#define Y second

const int N = 3e5+5;
const int K = 80;

vi G[N];
int p[N], dpth[N], num[N];
unsigned int dot[N], val[N];
vector<vi> ondpth;
bool chosen[N];
vector<unsigned int> memo[N];

void dfs(int v, int par, int dpt){
	p[v] = par;
	dpth[v] = dpt;
	dot[v] = dot[par] + val[v]*val[v];
	if(SZ(ondpth) == dpt) ondpth.PB({});
	ondpth[dpt].PB(v);
	TRAV(x, G[v]){
		if(x == par) continue;
		dfs(x, v, dpt+1);
	}
}

unsigned int query(int a, int b){
	unsigned int ret = 0;
	while(a != b && !chosen[a]){
		ret += val[a]*val[b];
		a = p[a];
		b = p[b];
	}
	if(a == b) ret += dot[a];
	else ret += memo[dpth[a]][num[a]*SZ(ondpth[dpth[a]])+num[b]];
	return ret;
}

void solve(){
	int n, q;
	cin >> n >> q;
	FOR(i, 1, n+1) cin >> val[i];
	FOR(i, 0, n-1){
		int a, b;
		cin >> a >> b;
		G[a].PB(b), G[b].PB(a);
	}
	dfs(1, 1, 0);
	ondpth.PB({});
	for(int i = 0; i < SZ(ondpth); i += K){
		ii akt = {INF, INF};
		FOR(j, i, min(i+K, SZ(ondpth))) akt = min(akt, {SZ(ondpth[j]), j});
		int lev = 0;
		TRAV(x, ondpth[akt.Y]) num[x] = lev++;
		TRAV(x, ondpth[akt.Y]) TRAV(y, ondpth[akt.Y]){
			if(num[x] <= num[y]) memo[akt.Y].PB(query(x, y));
			else memo[akt.Y].PB(memo[akt.Y][num[y]*lev+num[x]]);
		}
		TRAV(x, ondpth[akt.Y]) chosen[x] = 1;
	}
	FOR(i, 0, q){
		int a, b;
		cin >> a >> b;
		cout << query(a, b) << '\n';
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
