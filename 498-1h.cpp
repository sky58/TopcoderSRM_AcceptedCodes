//SRM498DIV1-1000 FoxJumping
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
int dpx[1610][810],dpy[1610][810];
int dp[1610][90];int co[1610][1610];
int mo=10007;
int cax(int x,int y){
	if(y>0) return (dpx[x][y]+mo-dpx[x][y-1])%mo;return dpx[x][y];
}
int cay(int x,int y){
	if(y>0) return (dpy[x][y]+mo-dpy[x][y-1])%mo;return dpy[x][y];
}
class FoxJumping{
	public:
	int FoxJumping::getCount(int tx,int ty,int mx,int my,int r,vector <int> bad){
		int i,j,k,txy=min(tx/10,ty/10),t=1,out=0;bad.pb(0);
		memset(dpx,0,sizeof(dpx));memset(dpy,0,sizeof(dpy));memset(dp,0,sizeof(dp));
		for(i=0;i<1610;i++) for(j=0;j<=i;j++){
			if(j==0 || j==i) co[i][j]=1;else co[i][j]=(co[i-1][j]+co[i-1][j-1])%mo;
		}
		for(i=0;i<810;i++) dpx[0][i]=dpy[0][i]=1;dp[0][0]=1;
		for(i=1;i<=r;i++) for(j=0;j<=tx;j++){
			dpx[i][j]+=dpx[i-1][j];
			if(j>mx) dpx[i][j]-=dpx[i-1][j-mx-1];
			if(j>0) dpx[i][j]+=dpx[i][j-1];
			dpx[i][j]+=2*mo;dpx[i][j]%=mo;
//			cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
		}
		for(i=1;i<=r;i++) for(j=0;j<=ty;j++){
			dpy[i][j]+=dpy[i-1][j];
			if(j>my) dpy[i][j]-=dpy[i-1][j-my-1];
			if(j>0) dpy[i][j]+=dpy[i][j-1];
			dpy[i][j]+=2*mo;dpy[i][j]%=mo;
		}
//		cout<<cax(2,2)<<' '<<cay(2,2)<<endl;cout<<dpx[2][2]<<' '<<dpy[2][2]<<endl;
		for(i=0;i<r;i++) for(j=0;j<=txy;j++) for(k=0;k<bad.size();k++){
			if(j+bad[k]/10<=txy) dp[i+1][j+bad[k]/10]=(dp[i+1][j+bad[k]/10]+dp[i][j])%mo;
		}
//		cout<<dp[1][1]<<' '<<cax(0,0)<<' '<<cay(0,0)<<endl;
		for(i=0;i<=r;i++){
			for(j=0;j<=txy;j++){
//				out+=(((dp[i][j]*dpx[r-i][tx-j*10])%mo*dpy[r-i][ty-j*10])%mo*co[r][i])%mo*t;
				out+=(((dp[i][j]*cax(r-i,tx-j*10))%mo*cay(r-i,ty-j*10))%mo*co[r][i])%mo*t;
				out+=mo*2;out%=mo;
			}
			t*=-1;
		}
		return out%mo;
	}
};
