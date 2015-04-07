//SRM593DIV1-1000 WolfDelaymasterHard
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
typedef int typ;
int wsum[2000010],osum[2000010],dp[1000010],x[1000010];
priority_queue<pint> q;
int mo=1000000007;
typ sum(int a,int b){
	if(a==0){
		typ s=0;
		for(int i=b;i>=0;i=(i&(i+1))-1) s=(s+x[i])%mo;
		return s;
	}
	else return (mo+sum(0,b)-sum(0,a-1))%mo;
}
void add(int ind,typ f){
	for(int i=ind;i<1000010;i|=i+1) x[i]=(x[i]+f)%mo;
}
class WolfDelaymasterHard{
	public:
	int countWords(int n, int wlen, int w0, int wmul, int wadd, int olen, int o0, int omul, int oadd){
		string a="";rep(i,n) a+='?';
		lint w=w0,o=o0;int t;
		rep(i,wlen){
			a[(int)w]='w';w=(w*wmul+wadd)%n;
		}
		rep(i,olen){
			a[(int)o]='o';o=(o*omul+oadd)%n;
		}
		rep(i,n){
			wsum[i+1]=wsum[i];osum[i+1]=osum[i];
			if(a[i]=='w') wsum[i+1]++;
			if(a[i]=='o') osum[i+1]++;
		}
		dp[0]=1;
		rep(i,n/2+1){
			while(q.size()){
				pint p=q.top();if(-p.fi>i) break;q.pop();add(p.se,mo-dp[p.se]);
			}
			if(i>0){
				t=lower_bound(wsum,wsum+n,wsum[i*2])-wsum;
				dp[i]=(dp[i]+sum(max(0,t-i),i-1));
			}
			if(i<n/2){
				add(i,dp[i]);
				t=upper_bound(osum,osum+n,osum[i*2])-osum;q.push(mp(i-t,i));
			}
		}
		return dp[n/2]%mo;
	}
};
