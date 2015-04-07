//SRM625DIV1-250 PalindromePermutations
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
int num[30];
class PalindromePermutations{
	public:
	double palindromeProbability(string a){
		double out=1.0;int n=a.size(),k=0;
		memset(num,0,sizeof(num));
		rep(i,n) num[(a[i]-'a')]++;
		rep(i,26) k+=num[i]%2;
		if(k>1) return 0.0;
		k=n;
		rep(i,26){
			rep(j,num[i]) out/=k-j;
			rep(j,num[i]) out*=j+1;
			k-=num[i];
		}
		//cout<<out<<endl;
		k=n/2;
		rep(i,26){
			num[i]/=2;
			rep(j,num[i]) out*=k-j;
			rep(j,num[i]) out/=j+1;
			k-=num[i];
		}
		//rep(i,n) out/=i+1;
		return out;
	}
};
