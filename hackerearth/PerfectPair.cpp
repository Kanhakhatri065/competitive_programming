#include<bits/stdc++.h>
    
using namespace std;
    
bool perf[2003];
    
void seive() {
    memset(perf,false,sizeof(perf));  
    for(int i=1;i*i<=2000;i++)
        perf[i*i]=true; 
    for(int i=0;i*i*i<=2000;i++)
        perf[i*i*i]=true;
    
}
    
bool isPerfect(int a) {
    return perf[a];
}
    
int main() {   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    seive();
        
    int t;
    cin>>t;
        
    while (t--) {
        int n,ans=0;
        cin>>n;
            
        int a[n],f[1003]={0};
            
        for(int i=0;i<n;i++)
            cin>>a[i],f[a[i]]++;
            
        for(int i=1;i<1003;i++) { 
            if(isPerfect(2*i))
                ans+=(f[i]*(f[i]-1)/2);
            
            for(int j=i+1;j<1003;j++)
                if(isPerfect(i+j))
                    ans+=(f[i]*f[j]);
            
        }
            
        cout<<ans<<'\n';
    }
        
    return 0;
    
}

