/*                             
    WAKE THE FUCK UP SAMURAI, WE HAVE A CITY TO BURN
    @Author: Divakar "h1s3nb3rg" Lakhera
*/

#define _USE_MATH_DEFINES
#include <bits/stdc++.h> 
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef uint64_t i64;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vector<ll>> v2ll;
const int MOD = 1e9+7;
#define NO cout<<"NO"<<ENDL;
#define YES cout<<"YES"<<ENDL;
#define INF  0x3f3f3f3f
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAIN int main(){FAST_IO;ll tc;cin>>tc;while(tc--){solver();}ret0;}
#define MAINKS int main(){FAST_IO;ll tc;cin>>tc;for(int i=1;i<=tc;i++){solver(i);}ret0;}
#define MAIN1 int main(){FAST_IO;solver();ret0;}
#define rep(i,b,e) for(__typeof(e)i=(b)-((b)>(e));i!=(e)-((b)>(e));i+=1-2*((b)>(e)))
#define repa(i,x)  for(auto i:x)
#define vin(x) for(auto &i:x){cin>>i;}
#define vin1(x) for(ll i=1;i<x.size();i++){cin>>x[i];}
#define dbg(x) for(auto i:x){cout<<i<<" ";}cout<<ENDL;
#define ENDL "\n"
#define VALL(a) a.begin(),a.end()
#define pfsum(x) partial_sum(VALL(x),x.begin())
#define li(x,_) ll x;cin>>x;ll _;cin>>_;
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define MP(a,b) make_pair(a,b)
#define ff first
#define ss second
#define ret0 return 0;
#define ret return;
#define ms(a,v) memset(a,v,sizeof(a));
#define pb(x) push_back(x)
/*----------------------------*/

typedef struct building{
    ll x,y,latency,connSpeed;
    building(ll a,ll b,ll c,ll d){
        x=a;
        y=b;
        latency=c;
        connSpeed=d;
    }
}bld;

typedef struct antenna{
    ll range,speed,id;
    antenna(ll r,ll s,ll ix){
        range = r;
        speed = s;
        id = ix;
    }
}ant;

vector<bld> buildings;
vector<ant> antennas;
ll xmax,ymax;
ll nBuildings;
ll nAntennas;
ll reward;

typedef struct outNode{
    ll x,y,id;
    outNode(ll a,ll b,ll c){
        x=a;
        y=b;
        id=c;
    }
}onode;

void solver(int arg = 0){
    cin >> xmax >> ymax;
    cin >> nBuildings >> nAntennas >> reward;
    for(int i=0;i<nBuildings;i++){
        ll x,y,l,c;
        cin>>x>>y>>l>>c;
        building tmp(x,y,l,c);
        buildings.push_back(tmp);
    }
    for(int i=0;i<nAntennas;i++){
        ll r,c;
        cin>>r>>c;
        antenna tmp(r,c,i);
        antennas.push_back(tmp);
    }
    /*
    sort(VALL(buildings),[](const building &a,const building &b){
        if(a.latency>b.latency)
            return true;
        else if(a.latency == b.latency){
            if(a.connSpeed > b.connSpeed)
                return true;
            else 
                return false;
        }
        return false; 
    });
    */

    sort(VALL(buildings),[](const building &a,const building &b){
        if(a.connSpeed > b.connSpeed)
            return true;
        else if(a.connSpeed == b.connSpeed)
            if(a.latency > b.latency) return true;
            else return false;
        return false;
    });




    sort(VALL(antennas),[](const antenna &a, const antenna &b){
        if(a.range > b.range)
            return true;
        else if(a.range == b.range)
            if(a.speed > b.speed) return true;
            else return false;
        return false;
    });

    /*
    for(auto bldt : buildings)
        cout<<bldt.x<<" "<<bldt.y<<" "<<bldt.latency<<" "<<bldt.connSpeed<<endl;
    
    for(auto anx : antennas)
        cout<<anx.range<<" "<<anx.speed<<endl;
    */
    
   ll taken = 0;
   vector<onode> ans;
   for(int i=0;i<nBuildings && nAntennas-taken>0; i++){
       taken++;
       ll x = buildings[i].x;
       ll y = buildings[i].y;
       ll id = antennas[i].id;
       onode tmp(x,y,id);
       ans.push_back(tmp);
   }
   cout<<ans.size()<<endl;
   for(auto i:ans) cout<<i.id<<" "<<i.x<<" "<<i.y<<endl;
    ret;
}

int main() {
    FAST_IO
    freopen("e.txt", "r", stdin);
    freopen("e_out.txt", "w", stdout);
    solver();
    return 0;
}