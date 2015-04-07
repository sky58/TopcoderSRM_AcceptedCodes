//SRM350DIV1-500 starryPahts
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
int con[55][55],st[55],dp[55];
class StarsInGraphs{
	public:
	int StarsInGraphs::starryPaths(vector <string> gr,int c){
		int i,j,k,n=gr.size(),out=0;memset(dp,0,sizeof(dp));memset(st,0,sizeof(st));memset(con,0,sizeof(con));
		con[0][0]=1;
		for(i=1;i<54;i++) for(j=0;j<54;j++){
			con[i][j]+=con[i-1][j];if(j>0) con[i][j]+=con[i-1][j-1];
//			cout<<con[i][j]<<endl;
		}
		for(i=0;i<n;i++){
			int t=0;
			for(j=0;j<n;j++){if(gr[i][j]=='1') t++;}
			for(j=3;j<=t;j++) st[i]+=con[t][j];
			if(st[i]>0 && st[i]<=c) dp[i]=1;
//			cout<<t<<' '<<st[i]<<endl;
		}
		for(k=0;k<100;k++){
			int f=0;
			for(i=0;i<n;i++) for(j=0;j<n;j++){
				if(gr[i][j]=='0' || st[i]<=0 || st[i]>c || st[j]<=0 || st[j]>c || st[i]>st[j]) continue;
				if(dp[j]<dp[i]+1){f=1;dp[j]=dp[i]+1;}
			}
			if(k>90 && f==1) return -1;
		}
		for(i=0;i<n;i++) out>?=dp[i];return out;
	}
};
