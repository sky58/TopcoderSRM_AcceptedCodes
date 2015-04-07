//SRM294DIV1-1000 DigitByDigit
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
vector <double> zyo;
double dp[55][55];
class DigitByDigit{
	public:
	double DigitByDigit::expectedScore(string a){
		int i,j,k,l,n=a.size(),s=0,u=0;double out=0.0;
		for(i=0;i<55;i++) for(j=0;j<55;j++) dp[i][j]=0.0;zyo.pb(1.0);for(i=0;i<55;i++) zyo.pb(zyo[i]*10);dp[0][0]=4.5;
		for(i=1;i<53;i++){
			for(j=0;j<10;j++){
				int mak=-1;double ma=0.0;
				for(k=0;k<=i;k++){
					double t=0.0;
					for(l=0;l<k;l++) t+=dp[i-1][l]*zyo[l];t+=zyo[k]*j;
					for(l=k;l<i;l++) t+=dp[i-1][l]*zyo[l+1];
					if(t>ma){ma=t;mak=k;}
				}
				for(l=0;l<mak;l++) dp[i][l]+=dp[i-1][l];dp[i][mak]+=j;for(l=mak;l<i;l++) dp[i][l+1]+=dp[i-1][l];
			}
			for(j=0;j<55;j++) dp[i][j]/=10;
		}
		reverse(a.begin(),a.end());for(i=0;i<n;i++){if(a[i]=='_') s++;}
		for(i=0;i<n;i++){
			if(a[i]=='_'){out+=dp[s-1][u]*zyo[i];u++;}else out+=zyo[i]*(a[i]-'0');
		}
		return out;
	}
};
