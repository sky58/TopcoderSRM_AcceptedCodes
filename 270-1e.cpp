//SRM270DIV1-300 CountriesRank
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
#define se second.first
#define th second.second
typedef pair<int,int> pint;
typedef pair<string,pint> sint;
map<string,int> me;vector <string> vs;
vector <int> maa,mii;
int ke[55],ka[55],ma[55],mi[55];
string moji(int a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}
class CountriesRanklist{
	public:
	vector <string> CountriesRanklist::findPlaces(vector <string> a){	
		int i,j,n=a.size(),it=1,t,la=1000000000;vector <sint> ret;vector <string> out;string s,s1;
		memset(ka,0,sizeof(ka));memset(ke,0,sizeof(ke));memset(ma,0,sizeof(ma));memset(mi,0,sizeof(mi));
//		for(i=0;i<55;i++) la[i]=1000000000;
		for(i=0;i<n;i++){
			istringstream sin(a[i]);sin>>s>>s1>>t;
			if(!me[s]){me[s]=it;it++;vs.pb(s);}
			ke[me[s]-1]+=t;ka[me[s]-1]++;la<?=t;
		}
		for(i=0;i<vs.size();i++){
			mi[i]=ke[i];ma[i]=ke[i]+(la-1)*(4-ka[i]);
		}
		for(i=0;i<vs.size();i++){
			int x=1,y=1;
			for(j=0;j<vs.size();j++){
				if(i==j) continue;
				if(mi[j]>ma[i]) x++;if(ma[j]>mi[i]) y++;
			}
			ret.pb(mp(vs[i],mp(x,y)));
		}
		sort(ret.begin(),ret.end());
		for(i=0;i<ret.size();i++){
//			stringstream sou;sou<<ret[i].fi<<' '<<ret[i].se<<' '<<ret[i].th;
			out.pb(ret[i].fi+' '+moji(ret[i].se)+' '+moji(ret[i].th));
		}
		return out;
	}
};
