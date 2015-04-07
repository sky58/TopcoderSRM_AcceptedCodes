//SRM488DIV1-500 TheBoringStoreDivOne
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
map<string,string> x,y;
bool ch(string a,string b){
	if(a.size()>b.size()) return true;if(a.size()<b.size()) return false;
	if(a<b) return true;return false;
}
class TheBoringStoreDivOne{
	public:
	string TheBoringStoreDivOne::find(string a,string b){
		int i,j,k,l,n=a.size(),m=b.size(),s,t;string c,d,e,f,out="";
		for(i=0;i<n;i++) for(j=1;i+j<=n;j++) for(k=i+j;k<n;k++) for(l=1;k+l<=n;l++){
			c=a.substr(i,j);d=a.substr(k,l);if(j>l){e=c;c=d;d=e;}s=c.size();t=d.size();
			if(d.substr(0,s)!=c) continue;f=d.substr(s,t-s);
			if(!x[f].size() || ch(c,x[f])) x[f]=c;
		}
		for(i=0;i<m;i++) for(j=1;i+j<=m;j++) for(k=i+j;k<m;k++) for(l=1;k+l<=m;l++){
			c=b.substr(i,j);d=b.substr(k,l);if(j>l){e=c;c=d;d=e;}s=c.size();t=d.size();
			if(d.substr(t-s,s)!=c) continue;f=d.substr(0,t-s);
			if(!y[f].size() || ch(c,y[f])) y[f]=c;
		}
		map<string,string>::iterator it=x.begin();
		while(it!=x.end()){
			c=(*it).first;d=(*it).second;it++;if(!y[c].size()) continue;if(ch(d+c+y[c],out)) out=d+c+y[c];
//			cout<<c<<' '<<d<<' '<<y[c]<<endl;
		}
		return out;
	}
};
int main()
{
	return 0;
}
