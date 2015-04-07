//SRM303DIV1-1000 FourBears(totyuu)
#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
int dp[55][150][2];int ka[55];int bitc[150];
bool su[150];
bool ch(int a,int b){
	int i,t=0;
	for(i=0;i<10;i++){
		if((a&(1<<i)) && (b&(1<<i))) t=1;
		if(i>0) if(!(a&(1<<i)) && a&(1<<(i-1)) && t==0) return true;
		if(!(a&(1<<i))) t=0;
	}
	return false;
}
class FourBears{
	public:
	int FourBears::clearPassages(vector <string> a){
		int n=a.size(),m=a[0].size(),s1=-1,s2=-1,g1=-1,g2=-1,i,j,k,l,inf=10000,out=inf;
		memset(su,false,sizeof(su));
		for(i=1;i<=n;i++) for(j=0;j<i;j++) su[(1<<i)-(1<<j)]=true;
		for(i=0;i<n;i++){
			if(a[i][0]=='B'){if(s1<0) s1=i;else s2=i;}
		}
		for(i=0;i<n;i++){
			if(a[i][m-1]=='B'){if(g1<0) g1=i;else g2=i;}
		}
//		cout<<s1<<' '<<s2<<' '<<g1<<' '<<g2<<endl;
		memset(ka,0,sizeof(ka));for(i=0;i<n;i++) for(j=0;j<m;j++){if(a[i][j]=='X') ka[j]+=(1<<i);}
		for(i=0;i<140;i++) bitc[i]=__builtin_popcount(i);
		for(i=0;i<150;i++) for(j=0;j<55;j++){dp[j][i][0]=inf;dp[j][i][1]=inf;}
		dp[0][(1<<s1)+(1<<s2)][0]=0;if(s2-s1==1) dp[0][(1<<s1)+(1<<s2)][1]=0;
		for(i=1;i<m-1;i++) for(j=0;j<(1<<n);j++){
			if(dp[i-1][j][0]>=inf && dp[i-1][j][1]>=inf) continue;
//			cout<<i-1<<' '<<j<<' '<<dp[i-1][j]<<endl;
			for(k=0;k<(1<<n);k++){
				if((k|ka[i])>k) continue;//if(ch(j,k)) continue;
				int t=0;
				for(l=0;l<n;l++){
					if(k&(1<<l)){
						if(j&(1<<l)) t|=(1<<l);
						if(l>0) if(t&(1<<(l-1))) t|=(1<<l);
					}
				}
				for(l=n-1;l>=0;l--){
					if(k&(1<<l)){
						if(j&(1<<l)) t|=(1<<l);
						if(l<n-1) if(t&(1<<(l+1))) t|=(1<<l);
					}
				}
//				cout<<t<<endl;
				if(su[t]) dp[i][t][1]<?=dp[i-1][j][0]+bitc[k-ka[i]];
				dp[i][t][0]<?=dp[i-1][j][0]+bitc[k-ka[i]];
				dp[i][t][1]<?=dp[i-1][j][1]+bitc[k-ka[i]];
			}
		}
		for(i=0;i<(1<<n);i++){if((i&(1<<g1)) && (i&(1<<g2))) out<?=dp[m-2][i][1];}
		if(g2-g1==1){out<?=dp[m-2][1<<g2][1];out<?=dp[m-2][1<<g1][1];}return out;
	}
};
