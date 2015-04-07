//SRM259DIV1-900 CardRemover
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
bool dp[55][55];int dp2[55];
class CardRemover{
	public:
	int CardRemover::calculate(vector <string> a){
		int i,j,k,l,n=a.size(),out=0;
		memset(dp,false,sizeof(dp));memset(dp2,0,sizeof(dp2));
		for(i=0;i<n-1;i++) dp[i][i+1]=true;
		for(int d=2;d<n;d++) for(i=0;i+d<n;i++){
			j=i+d;int f=0;
			for(k=0;k<26;k++){
				int f1=0,f2=0;
				for(l=0;l<3;l++){if(a[i][l]==(k+'A')) f1=1;if(a[j][l]==(k+'A')) f2=1;}
				if(f1>0 && f2>0) f++;
			}
			if(f<2) continue;
//			cout<<i<<' '<<j<<' '<<f<<endl;
			for(k=i+1;k<j;k++){if(dp[i][k] && dp[k][j]) dp[i][j]=true;}
		}
		for(i=0;i<n-1;i++) for(j=i+1;j<n;j++){if(dp[i][j]) dp2[j]>?=dp2[i]+j-i-1;}
//		for(i=0;i<n;i++) for(j=i+1;j<n;j++){if(dp[i][j]) cout<<i<<' '<<j<<endl;}
		for(i=0;i<n;i++) out>?=dp2[i];return out;
	}
};
