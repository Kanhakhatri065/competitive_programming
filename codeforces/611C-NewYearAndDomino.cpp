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
const int N = 2005;
char grid[N][N];
int h, w;

int hor[N][N], ver[N][N];
void solve() {
	cin >> h >> w;

	for(int i = 0;i < h;i++) {
		for(int j = 0;j < w;j++) {
			sc(grid[i][j]);
		}
	}

	for(int i = 0;i < h;i++) {
		for(int j = 0;j < w;j++) {
			hor[j + 1][i + 1] = hor[j][i + 1] + hor[j + 1][i] - hor[j][i];
			ver[j + 1][i + 1] = ver[j][i + 1] + ver[j + 1][i] - ver[j][i];

			if(grid[i][j] != '.') {
				continue;
			}

			if(j != w - 1 && grid[i][j + 1] == '.') hor[j + 1][i + 1]++;
			if(i != h - 1 && grid[i + 1][j] == '.') ver[j + 1][i + 1]++;
		}
	}

	int q;
	cin >> q;
	while(q--) {
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		x1--, y1--;
		int ans = 0;
		ans += hor[x2 - 1][y2] - hor[x1][y2] - hor[x2 - 1][y1] + hor[x1][y1];
		ans += ver[x2][y2 - 1] - ver[x1][y2 - 1] - ver[x2][y1] + ver[x1][y1];

		pf(ans);
	}
}

int main() {
	solve();
	return 0;
}
