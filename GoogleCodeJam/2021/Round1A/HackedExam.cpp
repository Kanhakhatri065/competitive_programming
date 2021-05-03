/*
    I love the sound you make when you shut up.
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
/*-------typedefs------*/
template<class T> using ordered_set = tree<T, null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update> ;
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
}
/*-------- test-case stuff--------------*/
#define ssolve solve();
#define msolve int T;cin >> T;while(T--) {solve();}
#define mcsolve int T;cin >> T;for(int tt = 1;tt <= T;tt++) {cout << "Case #" << tt << ": ";solve();}
/*-------- movement in a 2D array ------*/
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
/*----------------------------------------------------------------*/
const int MOD = 1e9 + 7;
const int N = 123;
/*-------------- Push your limits here ---------------------------*/
using Int = __int128;

Int gcd(Int x, Int y) {
	return y == 0 ? x : gcd(y, x % y);
}

Int CC[N][N];
int n, m;
string s[3];
int d[3];
string ans;
Int val[4];

void printInt(Int x) {
	if (x == 0) {
		cout << "0";
		return;
	}
	vector<int> w;
	while(x > 0) {
		w.push_back(x % 10);
		x /= 10;
	}
	reverse(all(w));
	for (int z : w) cout << z;
}

void printAns(Int p, Int q) {
	Int g = gcd(p, q);
	p /= g;
	q /= g;
	p = m * q - p;
    
    cout << ans << " ";	
	printInt(p);
	cout << "/";
	printInt(q);
    cout << endl;
}

void solve1() {
	if (2 * d[0] < m) {
		for (int i = 0; i < m; i++)
			ans[i] = s[0][i];
		printAns(d[0], 1);
	} else {
		for (int i = 0; i < m; i++)
			ans[i] = s[0][i] ^ ('F' ^ 'T');
		printAns(m - d[0], 1);
	}
}

void solve2() {
	int X = 0, Y = 0;
	for (int i = 0; i < m; i++) {
		if (s[0][i] == s[1][i]) {
			X++;
		} else {
			Y++;
		}
	}
	int x = d[0] + d[1] - Y;
	if (x < 0 || x > 2 * X || x % 2 == 1) throw;
	x /= 2;
	int y = d[0] - x;
	if (y < 0 || y > Y) throw;
	if (2 * x < X) {
		for (int i = 0; i < m; i++) {
			if (s[0][i] == s[1][i]) {
				ans[i] = s[0][i];
			}
		}
	} else {
		x = X - x;
		for (int i = 0; i < m; i++) {
			if (s[0][i] == s[1][i]) {
				ans[i] = s[0][i] ^ ('F' ^ 'T');
			}
		}
	}
	if (2 * y < Y) {
		for (int i = 0; i < m; i++) {
			if (s[0][i] != s[1][i]) {
				ans[i] = s[0][i];
			}
		}
	} else {
		y = Y - y;
		for (int i = 0; i < m; i++) {
			if (s[0][i] != s[1][i]) {
				ans[i] = s[0][i] ^ ('F' ^ 'T');
			}
		}
	}
	printAns(x + y, 1);
}


void solve3() {
	int A = 0, B = 0, C = 0, D = 0;
	for (int i = 0; i < m; i++) {
		if (s[0][i] == s[1][i]) {
			if (s[0][i] == s[2][i]) {
				A++;
			} else {
				B++;
			}
		} else {
			if (s[0][i] == s[2][i]) {
				C++;
			} else {
				D++;
			}
		}
	}
	for (int i = 0; i < 4; i++)
		val[i] = 0;
	Int Q = 0;
	for (int a = 0; a <= A; a++) {
		int b = d[0] + d[1] - C - D;
		if (b % 2 == 1) continue;
		b /= 2;
		b -= a;
		if (b < 0 || B < b) continue;
		int c = d[0] + d[2] - B - D;
		if (c % 2 == 1) continue;
		c /= 2;
		c -= a;
		if (c < 0 || C < c) continue;
		int e = d[0] - a - b - c;
		if (e < 0 || D < e) continue;
		Int cur = CC[A][a] * CC[B][b] * CC[C][c] * CC[D][e];
		Q += cur;
		val[0] += a * cur;
		val[1] += b * cur;
		val[2] += c * cur;
		val[3] += e * cur;
	}
	for (int i = 0; i < m; i++)
		ans[i] = s[0][i];
	if (2 * val[0] > A * Q) {
		val[0] = A * Q - val[0];
		for (int i = 0; i < m; i++) {
			if (s[0][i] == s[1][i] && s[0][i] == s[2][i])
				ans[i] ^= ('F' ^ 'T');
		}
	}
	if (2 * val[1] > B * Q) {
		val[1] = B * Q - val[1];
		for (int i = 0; i < m; i++) {
			if (s[0][i] == s[1][i] && s[0][i] != s[2][i])
				ans[i] ^= ('F' ^ 'T');
		}
	}
	if (2 * val[2] > C * Q) {
		val[2] = C * Q - val[2];
		for (int i = 0; i < m; i++) {
			if (s[0][i] != s[1][i] && s[0][i] == s[2][i])
				ans[i] ^= ('F' ^ 'T');
		}
	}
	if (2 * val[3] > D * Q) {
		val[3] = D * Q - val[3];
		for (int i = 0; i < m; i++) {
			if (s[0][i] != s[1][i] && s[0][i] != s[2][i])
				ans[i] ^= ('F' ^ 'T');
		}
	}
	printAns(val[0] + val[1] + val[2] + val[3], Q);
}


void solve() {
    cin >> n >> m;	
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> d[i];
		d[i] = m - d[i];
	}
    ans.resize(m); 
    if(n == 1) {
        solve1();
    } else if(n == 2){
        solve2();
    } else {
        solve3();
    }
}

int main() {
	for (int i = 0; i < N; i++) CC[i][0] = CC[i][i] = 1;
	for (int i = 0; i < N; i++)
		for (int j = 1; j < i; j++)
			CC[i][j] = CC[i - 1][j - 1] + CC[i - 1][j];

	go();
    mcsolve
	return 0;
}

