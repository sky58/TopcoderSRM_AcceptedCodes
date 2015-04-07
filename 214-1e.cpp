//SRM214DIV1-250 bloggoHyphenate
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
#define pf push_front
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
string cal(string x,string y,string z){
	int n=x.size(),m=y.size(),p,i,pos=-1000000;vector <int> t;
	rep(i,n){if(x[i]==' ') t.pb(i-t.size());}
	rep(i,m){if(y[i]=='-') p=i;}
	rep(i,t.size()){
		if(p==t[i]) return "correct";
		if(abs(p-pos)>abs(p-t[i])) pos=t[i];
	}
	if(pos<-100) return z;
	return z.substr(0,pos)+"-"+z.substr(pos);
}
class bloggoHyphenate{
	public:
	vector <string> bloggoHyphenate::correct(vector <string> a,vector <string> b){
		vector <string> c,d,out;string s="";int i,j,n=a.size(),m=b.size();
		rep(i,55){c.pb(s);d.pb(s);}
		rep(i,n) rep(j,a[i].size()){if(a[i][j]!=' ') c[i]+=a[i][j];}
		rep(i,m) rep(j,b[i].size()){if(b[i][j]!='-') d[i]+=b[i][j];}
		rep(j,m) rep(i,n){
			if(c[i]!=d[j]) continue;
//			cout<<i<<' '<<j<<endl;
			out.pb(cal(a[i],b[j],d[j]));
		}
		return out;
	}
};
