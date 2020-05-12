#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
#define ff first
#define ss second 
#define pp pair
#define ULRED 1000000007
#define MS(x,y) (x-y>0?x-y:y-x) 
#define MX3(a,b,c) (a>b?(a>c?a:c):(b>c?b:c))

void swapll(ll *a,ll *b){ll tmp=*a;*a=*b;*b=tmp;}
void swapc(char *a,char *b){char tmp=*a;*a=*b;*b=tmp;}
/*----------------------------------------------------------------*/

/*
int main() {
    int n, m, q;
    cin >> n >> m >> q;

    int arr[n][m];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++) {
            cin >> arr[i][j];
        }
    }

    int score[n];

    int count = 0;
    int max_eyes = 0;
    for(int i = 0;i < n;i++) {
        count = 0;
        for(int j = 0;j < m;j++) {
            if(arr[i][j] == 1) {
                count++;
            } else {
                if(count > max_eyes) {
                    max_eyes = count;
                }
                count = 0;
            }

            if(j == m - 1 && count != 0) {
                if(count > max_eyes) {
                    max_eyes = count;
                }
            }

        }
        score[i] = max_eyes;
    }


    int row,column;
    for(int i = 0;i < q;i++) {
        cin >> row >> column;
        if(arr[row - 1][column -1] == 0) {
            arr[row - 1][column - 1] = 1;
        } else if(arr[row -1][column - 1] == 1) {
            arr[row - 1][column - 1] = 0;
        }

        count = 0;
        int max_eyes = 0;
        for(int j = 0;j < m;j++) {
            if(arr[row - 1][j] == 1 ) {
                count++;
            } else {
                if(count > max_eyes) {
                    max_eyes = count;
                }
                count = 0;
            }

            if(j == m - 1 && count != 0) {
                if(count > max_eyes) {
                    max_eyes = count;
                }
            }

        }

        score[row - 1] = max_eyes;

        cout << *max_element(score, score + n) << endl;
    }


    return 0;
}

*/
ll gr(vector<vector<ll>> &v,ll p,ll n)
{
    ll ans=0;
    ll c=0;
    for(ll i=0;i<n;i++)
    {
        if(v[p][i]==1)
            c++;
        else
            c=0;
        ans=max(ans,c);
    }
    ans=max(ans,c);
    return ans;
}
 
int main(){
    FAST_IO;
    ll n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll>> v(n,vector<ll>(m,0));
    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
            cin>>v[i][j];
    vector<ll> mx(n,0);
    for(ll i=0;i<n;i++)
        mx[i]=gr(v,i,m);
    while(q--)
    {
        ll a,b;
        cin>>a>>b;
        a--;b--;
        if(v[a][b]==1)
            v[a][b]=0;
        else
            v[a][b]=1;
        mx[a]=gr(v,a,m);
        ll ans=-1;
        for(ll i=0;i<n;i++)
            ans=max(ans,mx[i]);
        cout<<ans<<endl;
    }
    return 0;
}