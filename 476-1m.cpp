//SRM476DIV1-550 FriendTour
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
vector <vector <int> > gr;//vector <int> cl;
double dp[(1<<16)+10][40];
double ke[40][40],co[40][40];
int en[40];int n;
double cal(int x,int y){
	if(dp[x][y]>-0.5) return dp[x][y];
	if(x==(1<<(n+1))-1) return 1.0;
	vector <double> a;int i;double ret=0.0;
	for(i=0;i<gr[y].size();i++){
		if(en[gr[y][i]]==-1) a.pb(0.0);
		else if(x&(1<<en[gr[y][i]])) a.pb(0.0);
		else a.pb(cal(x+(1<<en[gr[y][i]]),gr[y][i]));
	}
	sort(a.begin(),a.end());reverse(a.begin(),a.end());
	for(i=0;i<a.size();i++) ret+=ke[a.size()][i]*a[i];
//	cout<<x<<' '<<y<<' '<<ret<<endl;
	return dp[x][y]=ret;
}
class FriendTour{
	public:
	double FriendTour::tourProbability(vector <string> a,int b){
		memset(en,-1,sizeof(en));int i,j,t;
		for(i=0;i<40;i++) for(j=0;j<=i;j++){
			if(j==i || j==0) co[i][j]=1.0;else co[i][j]=co[i-1][j]+co[i-1][j-1];
		}
		for(i=1;i<40;i++) for(j=0;j<i;j++){
			if(i<=b){if(j<1) ke[i][j]=1.0;else ke[i][j]=0.0;}
			else if(i-j<b) ke[i][j]=0.0;else ke[i][j]=co[i-j-1][b-1]/co[i][b];
//			cout<<i<<' '<<j<<' '<<ke[i][j]<<endl;
		}
		for(i=0;i<a.size();i++){
			istringstream sin(a[i]);vector <int> c;while(sin>>t) c.pb(t-1);gr.pb(c);
		}
		n=gr[0].size();for(i=0;i<n;i++) en[gr[0][i]]=i;en[0]=n;//cout<<en[2]<<endl;
		for(i=0;i<(1<<16)+10;i++) for(j=0;j<40;j++) dp[i][j]=-1.0;return cal(1<<n,0);
	}
};
