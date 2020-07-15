#include<bits/stdc++.h>

using namespace std;

#define ll long long int


ll n,m,c;
ll BIT[1000001];

void update(ll index,ll k) {
    for(;index<=n;index+=(index&(-index))) {
       BIT[index]+=k;
    }
}
ll query(ll index) {
    ll ans=0;
    while(index>0) {
        ans+=BIT[index];
        index-=(index&(-index));
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>c;
    memset(BIT,0,sizeof(BIT));
    
    while(m--) {
        char type;
        cin>>type;
        if(type=='S') {
            ll u,v,k;
            cin>>u>>v>>k;
            update(u,k);
            update(v+1,-k);
        } else if(type=='Q') {
            ll p;
            cin>>p;
            cout<<c+query(p)<<"\n";
        }
    }
    return 0;
}
