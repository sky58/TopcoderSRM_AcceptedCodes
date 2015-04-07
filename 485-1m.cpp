//SRM485DIV1-500 RectangleAvoidingColoring
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
lint dp[55][5];
vector <string> tmp;
class RectangleAvoidingColoring{
	public:
	long long RectangleAvoidingColoring::count(vector <string> A){
		vector <string> a,b;int n=A.size(),m=A[0].size(),i,j,k,l,l2;
		tmp.pb("BBWW");tmp.pb("BWBW");tmp.pb("BWWB");tmp.pb("WBBW");tmp.pb("WBWB");tmp.pb("WWBB");
		for(i=0;i<55;i++) for(j=0;j<5;j++) dp[i][j]=0;
		if(n>m){
			for(i=0;i<m;i++){
				string s="";
				for(j=0;j<n;j++) s+=A[j][i];
				a.pb(s);
			}
			int d=m;m=n;n=d;
		}
		else a=A;b=a;
		if(n==1){
			lint t=0;
			for(i=0;i<m;i++){if(a[0][i]=='?') t++;}return (1LL<<t);
		}
		if(n==2){
			dp[0][0]=1;
			for(i=0;i<m;i++) for(j=0;j<4;j++){
				if(a[0][i]!='B' && a[1][i]!='W') dp[i+1][j]+=dp[i][j];
				if(a[1][i]!='B' && a[0][i]!='W') dp[i+1][j]+=dp[i][j];
				if(a[0][i]!='B' && a[1][i]!='B' && j<2) dp[i+1][j+2]+=dp[i][j];
				if(a[0][i]!='W' && a[1][i]!='W' && j%2==0) dp[i+1][j+1]+=dp[i][j];
			}
			return dp[m][0]+dp[m][1]+dp[m][2]+dp[m][3];
		}
		if(n<5){
			lint out=0;
			if(m<5){
				for(i=0;i<(1LL<<(m*n));i++){
					lint t=1;
					for(j=0;j<n;j++) for(k=0;k<m;k++){
						if(i&(1<<(j*m+k))) b[j][k]='B';else b[j][k]='W';
						if(a[j][k]!='?' && b[j][k]!=a[j][k]) t=0;
					}
					for(j=0;j<n-1;j++) for(k=j+1;k<n;k++) for(l=0;l<m-1;l++) for(l2=l+1;l2<m;l2++){
						if(b[j][l]==b[j][l2] && b[j][l]==b[k][l] && b[k][l]==b[k][l2]) t=0;
					}
					out+=t;
				}
				return out;
			}
			if(m<7){
				while(1){
					lint t=1;
					for(i=0;i<n;i++) for(j=0;j<m;j++){
						if(a[i][j]!='?' && a[i][j]!=tmp[j][i]) t=0;
					}
					out+=t;if(!next_permutation(tmp.begin(),tmp.end())) break;
				}
				return out;
			}
		}
		return 0;
	}
};
