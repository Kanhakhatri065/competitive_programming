#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        long int n;
        cin>>n;
        
        long int arr[n];
        for(long int i=0;i<n;i++)
            cin>>arr[i];
        
        sort(arr,arr+n);
        
        long int ctr=1,sum=0;
        
        long int i=0;
        for(int i=0;i<n;i++) {
            if(arr[i]==arr[i+1]) {
                ctr++;
            } else {
                sum+=ctr*(ctr+1)/2;
                ctr=1;
            }
        }
        cout<<sum<<endl;
    }
}
