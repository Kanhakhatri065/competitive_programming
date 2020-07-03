#include<iostream>
#include<stack>
#include<bits/stdc++.h>
#define FAST cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0)
#define mod 998244353
using namespace std;
long long modInverse(long long a)
{
	long long m0=998244353, m=998244353;
	long long y = 0, x = 1;

	while (a > 1)
	{
		long long q = a / m;
		long long t = m;

		m = a % m, a = t;
		t = y;

		y = x - q * y;
		x = t;
	}
	if (x < 0)
	x += m0;

	return x;
}
int main()
{
FAST;
int test;
cin>>test;
while(test--)
{
    string str;
    cin>>str;
    if(str.length()==1)
    {
        cout<<"748683265 748683265 748683265 748683265\n";
    }else{
        long long p=0,x=2,ans=1,v4=0;

        for(int j=0;j<str.length();j++)//count no of #
        {
            if(str[j]=='#')
            p++;
        }p*=4;//in terms of power of 2

        stack<vector<long long> > value;
        stack<char> oper;
        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='(')
            {
                oper.push(str[i]);
            }
            else if(str[i]=='#')
            {
                vector<long long> v;
                for(int j=0;j<3;j++)
                    v.push_back(4);
                value.push(v);
            }else if(str[i]==')')
            {
                while(!oper.empty() && oper.top()!='(')
                {
                    vector<long long> v1;
                    for(int j=0;j<3;j++)
                    {
                        v1.push_back(value.top()[j]);
                    }
                    value.pop();

                    vector<long long> v2;
                    for(int j=0;j<3;j++)
                    {
                        v2.push_back(value.top()[j]);
                    }
                    value.pop();

                    char op=oper.top();
                    oper.pop();

                    vector<long long> v3;
                    long long a,b,c,maxm;
                    if(op=='&')
                    {
                        a=(v1[1]*v2[0]+ (v2[0]+v2[1]+2*v2[2])*v1[0] + 2*v1[2]*(v2[0]+v2[2]));
                        b=(v1[1]*v2[1]);
                        c=(v1[1]*v2[2] + v1[2]*(v2[2]+v2[1])%mod);
                    }else if(op=='|')
                    {
                        a=(v1[0]*v2[0]);
                        b=(v1[0]*v2[1] + (v2[0]+v2[1]+2*v2[2])*v1[1] + 2*v1[2]*(v2[1]+v2[2]));
                        c=(v1[0]*v2[2] + v1[2]*(v2[2]+v2[0]));
                    }else if(op=='^')
                    {
                        a=(v1[0]*v2[0] + v1[1]*v2[1] + 2*v1[2]*v2[2]);
                        b=(v1[0]*v2[1] + v1[1]*v2[0] + 2*v1[2]*v2[2]);
                        c=(v2[2]*(v1[0]+v1[1]) + v1[2]*(v2[0]+v2[1]));
                    }
                    maxm=min(a&(~(a-1)),min(b&(~(b-1)),c&(~(c-1))));
                    v3.push_back(a/maxm%mod);
                    v3.push_back(b/maxm%mod);
                    v3.push_back(c/maxm%mod);
                    long long count=0;
                    while(maxm!=1)
                    {
                        maxm=maxm>>1;
                        count++;
                    }p-=count;
                    value.push(v3);
                    if(!oper.empty())
                        oper.pop();

                }
            }else//^ | &
            {
                oper.push(str[i]);
            }
        }
        while(p)//ans= 2^(4*no of #-unnecessary overhead)
        {
            if(p%2==1)
                ans=ans*(x%mod)%mod;
            x=(x%mod)*(x%mod);
            p/=2;
        }
        for(int j=0;j<3;j++)
        {
            v4=(value.top()[j]%mod)*(modInverse(ans))%mod;
            cout<<v4<<' ';
        }

        cout<<v4<<'\n';
    }
}
return 0;
}