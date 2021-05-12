#include <tuple>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
const int Maxn=2000;
int n;
int a[Maxn*3+5];
int dp[Maxn+5][Maxn+5];
int row_max[Maxn+5];
int zero,all_max;
vector<tuple<int,int,int> > vis;
void update(int i,int j,int k){
	vis.emplace_back(i,j,k);
	vis.emplace_back(j,i,k);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=3*n;i++){
		scanf("%d",&a[i]);
	}
	memset(row_max,-0x3f,sizeof row_max);
	memset(dp,-0x3f,sizeof dp);
	dp[a[1]][a[2]]=row_max[a[1]]=row_max[a[2]]=zero;
	for(int i=3;i<=3*n;i+=3){
		if(a[i]==a[i+1]&&a[i]==a[i+2]){
			zero--;
			continue;
		}
		for(int _=0;_<3;_++){
			swap(a[i],a[i+1]);
			swap(a[i+1],a[i+2]);
			update(a[i],a[i+1],max(all_max,dp[a[i+2]][a[i+2]]+1));
			for(int j=1;j<=n;j++){
				if(a[i+1]==a[i+2]){
					update(j,a[i],dp[j][a[i+1]]+1);
				}
				update(j,a[i],row_max[j]);
			}
		}
		for(tuple<int,int,int>j:vis){
			int e=get<0>(j),f=get<1>(j),g=get<2>(j);
			dp[e][f]=max(dp[e][f],g);
			row_max[e]=max(row_max[e],g);
			all_max=max(all_max,g);
		}
		vis.clear();
	}
	printf("%d\n",all_max-zero);
	return 0;
}

