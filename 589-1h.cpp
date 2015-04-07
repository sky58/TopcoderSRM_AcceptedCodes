//SRM589DIV1-900 FlippingBitsDiv1
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
int dp[310][2];
class FlippingBitsDiv1{
	public:
	int getmin(vector <string> S,int m){
		string s="";rep(i,S.size()) s+=S[i];
		int n=s.size(),l=(n+m-1)/m,inf=1000,out=inf;
		if(m<=17){
			rep(i,(1<<m)){
				rep(j,l+1) dp[j][0]=dp[j][1]=inf;dp[0][0]=0;
				rep(j,l){
					int ok=0,ng=0,d=1;if(j>0) d=2;
					rep(k,min(m,n-j*m)){
						if(((i>>k)&1)==(s[k+j*m]-'0')) ok++;else ng++;
					}
					dp[j+1][0]=min(dp[j+1][0],min(dp[j][0]+ng,dp[j][1]+ng));
					dp[j+1][1]=min(dp[j+1][1],min(dp[j][0]+ok+d,dp[j][1]+ok));
				}
				out=min(out,min(dp[l][0],dp[l][1]));//cout<<i<<' '<<dp[l][0]<<' '<<dp[l][1]<<endl;
			}
		}
		else{
			rep(i,(1<<l)){
				int ret=0;
				rep(j,l-1){
					if(!((1<<j)&i) && ((1<<(j+1))&i)) ret+=2;
				}
				if(i%2>0) ret++;
				rep(j,m){
					int on=0,ze=0;
					for(int k=0;k*m+j<n;k++){
						if(s[k*m+j]==(((i>>k)&1)+'0')) ze++;else on++;
					}
					ret+=min(ze,on);
				}
				out=min(ret,out);
			}
		}
		return out;
	}
};
