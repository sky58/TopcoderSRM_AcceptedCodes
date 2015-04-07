//SRM522DIV1-1050 PointErasing
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
#define All(s) s.begin(),s.end()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
bool able[60];bool dp[55][55];
vector <int> cal(vector <int> a){
	int n=a.size(),i,j,k;vector <int> ret;
	memset(dp,false,sizeof(dp));dp[0][0]=true;
	rep(i,n) rep(j,52){
		if(!dp[i][j]) continue;
		if(a[i]==a[0]) dp[i+1][j+1]=true;
		else{
			REP(k,i+1,n){
				if((lint)(a[i]-a[0])*(a[k]-a[0])<0) dp[k][j]=true;
			}
			dp[i+1][j]=dp[n][j]=true;
		}
	}
	rep(i,52){if(dp[n][i]) ret.pb(i);}return ret;
}
class PointErasing{
	public:
	vector <int> PointErasing::getOutcomes(vector <int> a){
		int ma=-1,mi=1100000000,mai=-1,mii=55,count=0,n=a.size(),i,j;
		memset(able,false,sizeof(able));
		rep(i,n){
			ma>?=a[i];mi<?=a[i];
		}
		rep(i,n){
			if(a[i]==ma || a[i]==mi){
				mai>?=i;mii<?=i;count++;
			}
		}
		vector <int> s1,s2,r1,r2,out;
		rep(i,mii) s1.pb(a[i]);r1=cal(s1);
		REP(i,mai+1,n) s2.pb(a[i]);reverse(All(s2));r2=cal(s2);
//		rep(i,r1.size()) cout<<r1[i]<<endl;rep(i,r2.size()) cout<<r2[i]<<endl;
		rep(i,r1.size()) rep(j,r2.size()) able[count+r1[i]+r2[j]]=true;
		rep(i,55){if(able[i]) out.pb(i);}return out;
	}
};
