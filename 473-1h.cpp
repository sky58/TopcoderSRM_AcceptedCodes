//SRM473DIV1-1000 RooksParty
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
lint con[1000][1000];
lint hai[12][33][33];
lint dp[12][33][33];
lint mo=1000000009;
class RooksParty{
	public:
	int RooksParty::countArrangements(int w,int h,vector <int> a){
		int n=a.size(),i,j,k,l,m;lint out=0;
		for(i=0;i<33;i++) for(j=0;j<33;j++) for(k=0;k<12;k++){dp[k][i][j]=0;hai[k][i][j]=0;}
		for(i=0;i<1000;i++) for(j=0;j<1000;j++) con[i][j]=0;con[0][0]=1;
		for(i=1;i<1000;i++) for(j=0;j<1000;j++){
			con[i][j]+=con[i-1][j];if(j>0) con[i][j]+=con[i-1][j-1];con[i][j]%=mo;
//			if(j<50) cout<<i<<' '<<j<<' '<<con[i][j]<<endl;
		}
		for(i=0;i<n;i++) for(j=1;j<=30;j++) for(k=1;k<=30;k++){
			hai[i][j][k]+=con[j*k][a[i]];
			for(l=1;l<=j;l++) for(m=1;m<=k;m++){
				if(l<j || m<k) hai[i][j][k]=(hai[i][j][k]+mo-((con[j][l]*con[k][m])%mo*hai[i][l][m])%mo)%mo;
			}
//			if(j<10 && k<10) cout<<j<<' '<<k<<' '<<hai[i][j][k]<<endl;
		}
		dp[0][w][h]=1;
		for(i=0;i<n;i++) for(j=1;j<=w;j++) for(k=0;k<=h;k++) for(l=0;l<j;l++) for(m=0;m<k;m++){
			dp[i+1][l][m]=(dp[i+1][l][m]+(((con[j][j-l]*con[k][k-m])%mo*hai[i][j-l][k-m])%mo*dp[i][j][k])%mo)%mo;
		}
		for(i=0;i<=w;i++) for(j=0;j<=h;j++) out=(out+dp[n][i][j]%mo);
		return (int)(out%mo);
	}
};
