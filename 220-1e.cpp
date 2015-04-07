//SRM220DIV1-300 HiddenNumbers
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
string pu(string a){
	int i,n=a.size();
	for(i=0;i<n;i++){
		if(a[i]!='0') break;
	}
	return a.substr(i,n-i);
}
bool ch(string a,string b){
	string c=pu(a),d=pu(b);
	if(c.size()>d.size()) return true;if(c.size()<d.size()) return false;
	if(c>d) return true;if(c<d) return false;
	if(a.size()>b.size()) return true;return false;
}
class HiddenNumbers{
	public:
	vector <string> HiddenNumbers::findAll(vector <string> a){
		int i,j;string b="",s="";vector <string> ret,out;
		for(i=0;i<a.size();i++) b+=a[i];
		for(i=0;i<b.size();i++){
			if(b[i]>'9' || b[i]<'0'){
				if(s.size()>0) ret.pb(s);s="";
			}
			else s+=b[i];//cout<<s<<endl;
		}
		if(s.size()>0) ret.pb(s);
		int n=ret.size();
		for(i=n-1;i>0;i--) for(j=0;j<i;j++){
			if(ch(ret[j],ret[j+1])){s=ret[j];ret[j]=ret[j+1];ret[j+1]=s;}
		}
		for(i=n/2;i<n;i++) out.pb(ret[i]);return out;
	}
};
