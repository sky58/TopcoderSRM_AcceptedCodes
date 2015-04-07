//SRM288DIV1-1000 CountryWar
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
bool gr[20][20];
double dp[(1<<15)+20][25];
int po[20];
double dp2[25][25][25];
int n,you,ene;
double rec(int a,int b,int c){
	if(dp2[a][b][c]>=0.0) return dp2[a][b][c];
	if(a<1) return dp2[a][b][c]=0.0;
	if(b<0){
		if(a==c) return dp2[a][b][c]=1.0;else return dp2[a][b][c]=0.0;
	}
	double t=1.0*a*a/(1.0*a*a+1.0*a*b+1.0*b*b);return dp2[a][b][c]=rec(a,b-1,c)*t+rec(a-1,b,c)*(1-t);
}
double rec2(int a,int b){
//	cout<<a<<' '<<b<<' '<<dp[a][b]<<endl;
	if(dp[a][b]>=0.0) return dp[a][b];
	if((a|(you+ene))==a && b>0) return 1.0;if(b<1) return 0.0;
	double ret=0.0;int i,j;
//	cout<<a<<' '<<b<<' '<<dp[a][b]<<endl;
	for(i=0;i<n;i++){
		double t=0.0;int f=0;if(a&(1<<i)) continue;
		for(j=0;j<n;j++){if((a&(1<<j)) && gr[j][i]) f=1;}
		if(f<1) continue;
		for(j=1;j<=b;j++) t+=rec2(a+(1<<i),j)*rec(b,po[i],j);
//		cout<<a<<' '<<i<<' '<<t<<endl;
		ret>?=t;
	}
//	cout<<a<<' '<<b<<' '<<ret<<endl;
	return dp[a][b]=ret;
}
class CountryWar{
	public:
	double CountryWar::defeatAll(vector <string> a){
		int i,j,k,x,you2;string s;n=a.size();you=0;ene=0;
		memset(gr,false,sizeof(gr));
		for(i=0;i<(1<<15)+20;i++) for(j=0;j<25;j++) dp[i][j]=-1.0;
		for(i=0;i<25;i++) for(j=0;j<25;j++) for(k=0;k<25;k++) dp2[i][j][k]=-1.0;
		for(i=0;i<n;i++){
			istringstream sin(a[i]);sin>>s;sin>>x;po[i]=x;
			while(sin>>x) gr[i][x]=true;
			if(s=="Y"){you2=i;you+=(1<<i);}if(s=="E") ene+=(1<<i);;
		}
		return rec2(you,po[you2]);
	}
};
