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
int s, ra, pa, rb, pb, c;
int vis[20][20];
int dfs(int ra, int pa, int rb, int pb, int state, int trouble) {
	pair <int,int> x={ra,rb};
	pair <int,int> y={pa,pb};
	vector <pair <int,int> > neigh;
	if(y.first%2==0) {
		if(vis[x.first-1][y.first-1]==0) {
			neigh.push_back({x.first-1,y.first-1});
		}	
	} else {
		if(vis[x.first+1][y.first+1]==0) {
			neigh.push_back({x.first+1,y.first+1});
		}
	}

	if(vis[x.first][y.first+1]==0) {
		neigh.push_back({x.first,y.first+1});
	}
	if(vis[x.first][y.first-1]==0) {
		neigh.push_back({x.first,y.first-1});
	}

	if(neigh.size()==0) {
		if(trouble>=1) {
			return 0;
		}
		
		int ret=dfs(x.second,y.second,x.first,y.first,state^1,trouble+1);
		return ret;
	}
	else {
		if(state==0) {
			int ret=-mod;
			for(auto i: neigh) {
				vis[i.first][i.second]++;
				ret=max(1+dfs(x.second,y.second,i.first,i.second,state^1,0),ret);
				vis[i.first][i.second]--;
			}
			return ret;
		} else {
			int ret=mod;
			for(auto i: neigh) {
				vis[i.first][i.second]++;
				ret=min(dfs(x.second,y.second,i.first,i.second,state^1,0)-1,ret);
				vis[i.first][i.second]--;
			}
			return ret;
		}
	}

	return 0;
}

void solve() {
    cin >> s >> ra >> pa >> rb >> pb >> c;

    memset(vis, 0, sizeof(vis));

    for(int i = 0;i < 20;i++) {
        for(int j = 0;j < 20;j++) {
            if(i == 0 || j == 0 || i > s || j > 2 * i - 1) {
                vis[i][j] = 1;
            }
        }
    }

    for(int i = 0;i < c;i++) {
        int ri, pi;
        cin >> ri >> pi;
        vis[ri][pi] = 1;
    }

    vis[ra][pa] = 1;
    vis[rb][pb] = 1;
    pf(dfs(ra, pa, rb, pb, 0, 0));
}

int main() {
    go();
    int t;
    sc(t);

    for(int tt = 1;tt <= t;tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }

    return 0;
}