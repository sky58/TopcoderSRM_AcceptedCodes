//SRM215DIV1-500 Thesaurus
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
bool sumi[55];
int ch(vector <string> a,vector <string> b){
	int i,j,n=a.size(),m=b.size(),ret=0;
	rep(i,n) rep(j,m){
		if(a[i]==b[j]) ret++;
	}
	return ret;
}
vector <string> re(vector <string> in){
	sort(All(in));vector <string> ret;int i,n=in.size();
	ret.pb(in[0]);
	rep(i,n-1){if(in[i]!=in[i+1]) ret.pb(in[i+1]);}return ret;
}
class Thesaurus{
	public:
	vector <string> Thesaurus::edit(vector <string> a){
		memset(sumi,false,sizeof(sumi));
		int i,j,k,l,n=a.size();string s;
		vector <vector <string> > b;vector <string> out;
		rep(i,n){
			istringstream sin(a[i]);vector <string> c;
			while(sin>>s) c.pb(s);b.pb(c);
		}
		rep(i,55){
			rep(j,n-1) REP(k,j+1,n){
				if(sumi[j] || sumi[k]) continue;
				if(ch(b[j],b[k])>1){
					rep(l,b[k].size()) b[j].pb(b[k][l]);
					b[j]=re(b[j]);sumi[k]=true;
				}
			}
		}
		rep(i,n){
			if(sumi[i]) continue;
			sort(All(b[i]));s="";
			rep(j,b[i].size()){
				s+=b[i][j];if(j<b[i].size()-1) s+=" ";
			}
			out.pb(s);
		}
		sort(All(out));return out;
	}
};
