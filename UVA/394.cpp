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
typedef map<string, int> msi;

struct Array {
	int dim;
	int base;
	int size;
	string name;
	int U[10];
	int L[10];
	int C0;
	int C[10];
};

int main(){
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	int N(0), R(0);

	cin >> N >> R;

	msi nameIndexMap;
	vector<Array> arrays;
	struct Array arr = {};

	for (int i = 0; i < N; i++){
		
		cin >> arr.name;
		cin	>> arr.base >> arr.size >> arr.dim;
		
		for (int d = 0; d < arr.dim; d++)
			cin >> arr.L[d] >> arr.U[d];

		//calculate constants
		arr.C[arr.dim-1] = arr.size;
		arr.C0 = arr.base - (arr.C[arr.dim-1]*arr.L[arr.dim-1]);
		for (int j = arr.dim - 2; j >= 0; j--){
			arr.C[j] = (arr.C[j+1])*(arr.U[j+1] - arr.L[j+1] + 1);
			arr.C0 = arr.C0 - (arr.C[j] * arr.L[j]);
		}
		
		nameIndexMap[arr.name] = i;
		arrays.push_back(arr);
	}

	string arrName;
	int indice(0);
	long long address(0);
	for (int i = 0; i < R; i++){
		cin >> arrName;
		indice = nameIndexMap[arrName];

		cout << arrName << "[";

		arr = arrays[indice];
		address = arr.C0;
		for (int j = 0; j < arr.dim; j++){
			cin >> indice;
			address += arr.C[j] * indice;

			cout << indice;
			if (j != (arr.dim - 1)){
				cout << ", ";
			} else{
				cout << "]";
			}
		}

		cout << " = " << address << endl;
	}

	return 0;
}