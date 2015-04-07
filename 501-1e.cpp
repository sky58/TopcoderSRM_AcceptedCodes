//SRM501DIV1-250 FoxPlayingGame
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
double dp[55][55];
class FoxPlayingGame{
	public:
	double FoxPlayingGame::theMax(int na,int nb,int pa,int pb){
		int i;double out=0.001*pa*na;
/*		for(i=0;i<55;i++) for(j=0;j<55;j++) dp[i][j]=-1e20;dp[0][0]=0;
		for(i=0;i<=na;i++) for(j=0;j<=nb;j++){
			dp[i+1][j]>?=dp[i][j]+(0.001*pa);dp[i][j+1]>?=dp[i][j]*(0.001*pb);
		}
		return dp[na][nb];
*/
		if(out>=0.0){
			if(abs(pb)<=1000) return out;
			if(pb>0){for(i=0;i<nb;i++) out*=(0.001*pb);return out;}
			for(i=0;i<nb/2;i++){out*=(0.001*pb);out*=(0.001*pb);}return out;
		}
		if(pb<0 && nb>0){
			out*=(0.001*pb);nb--;
			if(abs(pb)<=1000) return out;
			for(i=0;i<nb/2;i++){out*=(0.001*pb);out*=(0.001*pb);}return out;
		}
		if(pb>1000) return out;
		for(i=0;i<nb;i++) out*=(0.001*pb);return out;
	}
};
