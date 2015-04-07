//SRM495DIV1-975 StrangeElevator
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
int dp[500000][10][2];
int mo=1000000007;
bool so[100000];
vector <int> n1,n2,n3,m1,m2,m3;
vector <int> dec(int a,vector <int> b){
	vector <int> ret;
	for(int i=0;i<b.size();i++){
		ret.pb(a%(b[i]+1));a/=(b[i]+1);
	}
	return ret;
}
class StrangeElevator{
	public:
	int StrangeElevator::theCount(int h,int n){
		int i,j,k,m=h/n,out=0;
		if(h%n!=0) return 0;
		if(m<2 || n<2) return 1;
		memset(so,false,sizeof(so));
		for(i=2;i<100000;i++){
			if(so[i]) continue;
			if(n%i==0) n1.pb(i);if(m%i==0) m1.pb(i);
			for(j=i+i;j<100000;j+=i) so[j]=true;
		}
		for(i=0;i<n1.size();i++){int t=0;while(n%n1[i]==0){n/=n1[i];t++;}n2.pb(t);}
		if(n>1){n1.pb(n);n2.pb(1);}
		for(i=0;i<m1.size();i++){int t=0;while(m%m1[i]==0){m/=m1[i];t++;}m2.pb(t);}
		if(m>1){m1.pb(m);m2.pb(1);}
		n=n1.size();m=m1.size();n3.pb(1);m3.pb(1);
		for(i=0;i<n;i++) n3.pb(n3[i]*(n2[i]+1));for(i=0;i<m;i++) m3.pb(m3[i]*(m2[i]+1));
		memset(dp,0,sizeof(dp));dp[0][0][0]=1;
//		for(i=0;i<n;i++) cout<<n1[i]<<' '<<n2[i]<<endl;for(i=0;i<m;i++) cout<<m1[i]<<' '<<m2[i]<<endl;
		for(i=0;i<n3[n]*m3[m];i++){
			int x=i/m3[m],y=i%m3[m];vector <int> x1=dec(x,n2),y1=dec(y,m2);
			for(j=0;j<n;j++){
				if(x1[j]>=n2[j]) continue;
				for(k=0;k<=j;k++) dp[(x+n3[j])*m3[m]+y][j][0]=(dp[(x+n3[j])*m3[m]+y][j][0]+dp[i][k][0])%mo;
				for(k=0;k<m;k++) dp[(x+n3[j])*m3[m]+y][j][0]=(dp[(x+n3[j])*m3[m]+y][j][0]+dp[i][k][1])%mo;
			}
			for(j=0;j<m;j++){
//				if(j==0) cout<<y+ma[j]
				if(y1[j]>=m2[j]) continue;
//				if(j==0) cout<<y+m3[j]<<endl;
				for(k=0;k<=j;k++) dp[x*m3[m]+y+m3[j]][j][1]=(dp[x*m3[m]+y+m3[j]][j][1]+dp[i][k][1])%mo;
				for(k=0;k<n;k++) dp[x*m3[m]+y+m3[j]][j][1]=(dp[x*m3[m]+y+m3[j]][j][1]+dp[i][k][0])%mo;
			}
//			for(j=0;j<n;j++) cout<<x<<' '<<y<<' '<<j<<' '<<dp[i][j][0]<<"a\n";
//			for(j=0;j<m;j++) cout<<x<<' '<<y<<' '<<j<<' '<<dp[i][j][1]<<"b\n";
		}
		for(i=0;i<n;i++) out=(out+dp[n3[n]*m3[m]-1][i][0])%mo;for(i=0;i<m;i++) out=(out+dp[n3[n]*m3[m]-1][i][1])%mo;
		return out;
	}
};
