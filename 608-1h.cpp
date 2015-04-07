//SRM608DIV1-900 OneDimensionalRobot
#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int dp[5140][5140];
class OneDimensionalRobot{
	public:
	long long theSum(vector<string> a,vector<string> b,int mina,int maxa,int minb,int maxb){
		string s="";rep(i,a.size()) s+=a[i];rep(i,b.size()) s+=b[i];
		int l=0,r=0,now=0;lint out=0;
		rep(i,s.size()){
			if(s[i]=='L') now--;else now++;
			l=max(l,-now);r=max(r,now);
		}
		REP(i,mina,maxa+1) REP(j,minb,maxb+1){
			if(i>mina && j<maxb){
				dp[i][j]=dp[i-1][j+1];
				if(l>i-1 || r>j) dp[i][j]--;
			}
			else if(l<=i && r<=j) dp[i][j]=now;
			else{
				int n2=0;
				rep(k,s.size()){
					if(s[k]=='L') n2--;else n2++;
					n2=max(n2,-i);n2=min(n2,j);
				}
				dp[i][j]=n2;
			}
			out+=dp[i][j];
		}
		return out;
	}
};
