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
const int N = 70;
const int INF = 1e9;

int a[N][N];
int dp[N][N][N][N];
int n, m, k;
void solve() {
	cin >> n >> m >> k;

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			cin >> a[i][j];
		}
	}

	for(int i = 0;i < N;i++) {
		for(int j = 0;j < N;j++) {
			for(int cnt = 0;cnt < N;cnt++) {
				for(int rem = 0;rem < N;rem++) {
					dp[i][j][cnt][rem] = -INF;
				}
			}
		}
	}

	dp[0][0][0][0] = 0;
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			for(int cnt = 0;cnt < ((m / 2) + 1);cnt++) {
				for(int rem = 0;rem < k;rem++) {
					if(dp[i][j][cnt][rem] == -INF) {
						continue;
					}

					int ni = (j == m - 1 ? i + 1 : i);
					int nj = (j == m - 1 ? 0 : j + 1);

					if(i != ni) {
						dp[ni][nj][0][rem] = max(dp[ni][nj][0][rem], dp[i][j][cnt][rem]);
					} else {
						dp[ni][nj][cnt][rem] = max(dp[ni][nj][cnt][rem], dp[i][j][cnt][rem]);
					}

					if(cnt + 1 <= (m / 2)) {
						int nrem = (rem + a[i][j]) % k;
						if(i != ni) {
							dp[ni][nj][0][nrem] = max(dp[ni][nj][0][nrem], dp[i][j][cnt][rem] + a[i][j]);
						} else {
							dp[ni][nj][cnt + 1][nrem] = max(dp[ni][nj][cnt + 1][nrem], dp[i][j][cnt][rem] + a[i][j]);
						}
					}
				}
			}
		}
	}

	pf(max(0, dp[n][0][0][0]));
}

int main() {
	solve();
	return 0;
}
