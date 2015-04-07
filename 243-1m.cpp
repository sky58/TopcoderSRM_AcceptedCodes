//SRM243DIV1-500 TopFive
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
double dp[55][10];
class TopFive{
	public:
	double TopFive::findProbability(vector <string> a,vector <string> b,int c){
		int i,j,k,n=a.size();int x[5],y[5];double out=0.0;
		for(i=0;i<55;i++) for(j=0;j<10;j++) dp[i][j]=0.0;dp[0][0]=1.0;
		for(i=0;i<n;i++){
			istringstream sin(a[i]);sin>>x[0]>>x[1]>>x[2];
			istringstream sin2(b[i]);sin2>>y[0]>>y[1]>>y[2];double f=0.0;
			for(j=0;j<8;j++){
				double t=1.0;int ke=0;
				for(k=0;k<3;k++){
					if(j&(1<<k)){ke+=x[k];t*=0.01*y[k];}else t*=0.01*(100-y[k]);
				}
				if(ke>=c) f+=t;
			}
			for(j=0;j<5;j++){
				dp[i+1][j]+=dp[i][j]*(1.0-f);dp[i+1][j+1]+=dp[i][j]*f;
			}
		}
		for(i=0;i<5;i++) out+=dp[n][i];return out;
	}
};
