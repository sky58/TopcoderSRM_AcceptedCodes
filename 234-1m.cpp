//SRM234DIV1-650 WeirdRooks
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
bool dp[10][1030][82][10];
bool ret[100][100];
string moji(int a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}
class WeirdRooks{
	public:
	string WeirdRooks::describe(vector <int> a){
		int i,j,k,l,m,n=a.size();memset(ret,false,sizeof(ret));string out="";
		memset(dp,false,sizeof(dp));dp[0][0][0][0]=true;
		for(i=0;i<n;i++) for(j=0;j<(1<<10);j++) for(k=0;k<=10*i;k++) for(l=0;l<=i;l++){
			if(!dp[i][j][k][l]) continue;int f=0;
			for(m=0;m<a[i];m++){
				if(!(j&(1<<m))){
					dp[i+1][j+(1<<m)][k+f][l+1]=true;f++;
				}
			}
			dp[i+1][j][k+f][l]=true;
		}
		for(i=0;i<(1<<10);i++) for(j=0;j<81;j++) for(k=0;k<9;k++){
			if(dp[n][i][j][k]) ret[k][j]=true;
		}
		for(i=0;i<9;i++) for(j=0;j<81;j++){
			if(ret[i][j]) out+=moji(i)+','+moji(j)+' ';
		}
		return out.substr(0,out.size()-1);
	}
};
