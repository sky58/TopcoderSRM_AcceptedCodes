//SRM478DIV1-1000 RandomApple
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
int ka[55][55];int ke[55];
double pr[55][55];
lint dp[510000],dp2[510000];
vector <lint> zyo;
class RandomApple{
	public:
	vector <double> RandomApple::theProbability(vector <string> a,vector <string> b,vector <string> c){
		int n=a.size(),m=a[0].size(),i,j;vector <double> out;
		for(i=0;i<m;i++) out.pb(0.0);memset(ke,0,sizeof(ke));for(i=0;i<510000;i++) dp[i]=0;dp[0]=1;
		zyo.pb(1);for(i=0;i<55;i++) zyo.pb(zyo[i]*2);
		for(i=0;i<n;i++) for(j=0;j<m;j++) ka[i][j]=(a[i][j]-'0')*100+(b[i][j]-'0')*10+(c[i][j]-'0');
		for(i=0;i<n;i++) for(j=0;j<m;j++) ke[i]+=ka[i][j];
		for(i=0;i<n;i++) for(j=0;j<m;j++) pr[i][j]=1.0*ka[i][j]/ke[i];
		for(i=0;i<n;i++) for(j=505000;j>=ke[i];j--) dp[j]+=dp[j-ke[i]];
		for(i=0;i<n;i++){
			for(j=0;j<505000;j++){
				dp2[j]=dp[j];if(j>=ke[i]) dp2[j]-=dp2[j-ke[i]];
			}
			double f=0.0;
			for(j=0;j<505000;j++) f+=1.0*dp2[j]*ke[i]/(j+ke[i]);
			f/=zyo[n]-1;
			for(j=0;j<m;j++) out[j]+=pr[i][j]*f;
		}
		return out;
	}
};
