//SRM619DIV1-1000 SimilarSequencesAnother
#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
lint dp[114][19][1919];
int d2[4][4];
int de[15][4]={{0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},{0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1},{0,0,1,2},{0,1,0,2},{0,1,1,2},{0,1,2,0},{0,1,2,1},{0,1,2,2},{0,1,2,3}};
int ma[16],en[364],nex[5],now[5],sumi[7];
int di[5]={0,1,2,1,0};
int cal(int a,int b,int c,int d){
	memset(sumi,-1,sizeof(sumi));
	int t=0;
	/*if(b>t){t++;if(b==c) c=t;if(b==d) d=t;b=t;}
	if(c>t){t++;if(c==d) d=t;c=t;}
	if(d>t){t++;d=t;}*/
	if(sumi[a]<0) sumi[a]=t++;if(sumi[b]<0) sumi[b]=t++;if(sumi[c]<0) sumi[c]=t++;if(sumi[d]<0) sumi[d]=t++;
	a=sumi[a];b=sumi[b];c=sumi[c];d=sumi[d];
	return 64*a+16*b+4*c+d;
}
class SimilarSequencesAnother{
	public:
	int getCount(int n,int a){
		lint out=0,mo=1000000009;
		if(n<3){
			lint ret=1;rep(i,n*2) ret=(ret*a)%mo;return (int)(ret%mo);
		}
		memset(ma,0,sizeof(ma));memset(en,-1,sizeof(en));
		rep(i,15){
			int t=0;rep(j,4) t=t*4+de[i][j],ma[i]=max(ma[i],de[i][j]);en[t]=i;
			if(ma[i]>=a) continue;
			memset(d2,0,sizeof(d2));
			rep(j,3) rep(k,3){
				if(j<2) d2[j+1][k]=max(d2[j+1][k],d2[j][k]);
				if(k<2) d2[j][k+1]=max(d2[j][k+1],d2[j][k]);
				if(j<2 && k<2 && de[i][j]==de[i][k+2]) if(j<2) d2[j+1][k+1]=max(d2[j+1][k+1],d2[j][k]+1);
			}
			nex[0]=nex[4]=0;nex[1]=1-d2[2][1];nex[2]=2-d2[2][2];nex[3]=1-d2[1][2];
			t=0;rep(j,5) t=t*4+nex[j];
			dp[2][i][t]=1;rep(j,ma[i]+1) dp[2][i][t]=(dp[2][i][t]*(a-j))%mo;
		}
		REP(i,2,n) rep(j,15) rep(k,1024){
			if(dp[i][j][k]<1) continue;
			int t=k;//lint ne=dp[i][j][k];
			rep(l,5){now[4-l]=di[l]-t%4;t/=4;}
			//rep(l,4) cout<<de[j][l]<<' ';rep(l,5) cout<<now[l]<<' ';cout<<dp[i][j][k]<<endl;
			rep(l,min(a,ma[j]+2)){
				lint ne2=dp[i][j][k];
				if(l>ma[j]) ne2=(ne2*(a-ma[j]-1))%mo;
				int nma=max(ma[j],l);
				rep(m,min(a,nma+2)){
					lint ne=ne2;if(m>nma) ne=(ne*(a-nma-1))%mo;
					
					nex[0]=now[1];nex[1]=now[2];nex[3]=now[2];nex[4]=now[3];nex[2]=0;
					if(l==de[j][2]) nex[0]=max(nex[0],now[0]+1);
					if(l==de[j][3]) nex[1]=max(nex[1],now[1]+1);
					if(m==de[j][0]) nex[4]=max(nex[4],now[4]+1);
					if(m==de[j][1]) nex[3]=max(nex[3],now[3]+1);
					nex[1]=max(nex[0],nex[1]);nex[2]=max(nex[2],nex[1]);nex[3]=max(nex[3],nex[4]);nex[2]=max(nex[2],nex[3]);
					if(m==l) nex[2]=max(nex[2],now[2]+1);//cout<<k<<m<<l<<endl;
					//if(j==3 && l==0 && m==1){rep(o,5) cout<<nex[o]<<' ';cout<<endl;}
					rep(o,5) nex[o]=min(3,di[o]-nex[o]+1);
					t=0;rep(o,5) t=t*4+nex[o];
					int s=cal(de[j][1],l,de[j][3],m);//cout<<de[j][1]<<' '<<l<<' '<<de[j][3]<<' '<<m<<' '<<en[s]<<endl;
					dp[i+1][en[s]][t]+=ne;dp[i+1][en[s]][t]%=mo;
				}
			}
		}
		rep(i,15) rep(j,1024){
			if(dp[n][i][j]<1) continue;
			int t=j;rep(k,5){now[4-k]=t%4;t/=4;}
			//rep(l,4) cout<<de[i][l]<<' ';rep(l,5) cout<<di[l]+1-now[l]<<' ';cout<<dp[n][i][j]<<endl;
			if(now[2]<3) out=(out+dp[n][i][j])%mo;
		}
		return (int)(out%mo);
	}
};
