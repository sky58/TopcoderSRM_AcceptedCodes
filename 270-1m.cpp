//SRM270DIV1-600 SalesmansDilemma
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
int ha[55],ow[55],co[55];
lint dp[55];
lint inf=-10000000000000000LL;
bool flo[55][55];bool ko[55];
string moji(lint a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}
class SalesmansDilemma{
	public:
	string SalesmansDilemma::bestRoute(int n,int s,int g,vector <string> a,vector <int> p){
		int m=a.size(),i,j,k;memset(flo,false,sizeof(flo));memset(ko,false,sizeof(ko));
		for(i=0;i<m;i++){
			istringstream sin(a[i]);sin>>ha[i]>>ow[i]>>co[i];flo[ha[i]][ow[i]]=true;
		}
		for(i=0;i<55;i++) flo[i][i]=true;
		for(k=0;k<55;k++) for(i=0;i<55;i++) for(j=0;j<55;j++){if(flo[i][k] && flo[k][j]) flo[i][j]=true;}
		for(i=0;i<55;i++) dp[i]=inf;dp[s]=p[s];
		for(i=0;i<500;i++) for(j=0;j<m;j++){
			if(dp[ha[j]]<=inf) continue;
			if(dp[ow[j]]<dp[ha[j]]-co[j]+p[ow[j]]){
				dp[ow[j]]=dp[ha[j]]-co[j]+p[ow[j]];if(i>400) ko[ow[j]]=true;
			}
		}
		for(i=0;i<n;i++){if(ko[i] && flo[i][g]) return "ENDLESS PROFIT";}
		if(dp[g]<=inf) return "IMPOSSIBLE";return  "BEST PROFIT: "+moji(dp[g]);
	}
};
