#include<bits/stdc++.h>

using namespace std;

int main ()
{
    int t,a,b,c;

    cin>>t;

    long long sum=0;

    string s;


    while ( t-- )
    {
        cin>>s;
        if(s=="donate")
        {
            cin>>a;
            sum=sum+a;
        }
        else
        {
            cout<<sum<<endl;
        }
    }

    return 0;
}