//SRM265DIV1-500 Recipe
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
map<string,int> de;
int hi[55],im[55],hi2[55];
string na[55];
int gcd( int m, int n )
{
	int a=max(m,n),b=min(m,n);
	if(m==0) return n;if(n==0) return m;
	if(a%b==0) return b;
	return gcd(b,a-b*(a/b));
}
string moji(int a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}
string cal(int t){
	string ret="";
	if(t/48>0){ret+=moji(t/48);ret+=" cups ";}t%=48;
	if(t/3>0){ret+=moji(t/3);ret+=" Tbsp ";}t%=3;
	if(t>0){ret+=moji(t);ret+=" tsp ";}
	return ret;
}
class Recipe{
	public:
	vector <string> Recipe::fix(vector <string> a,vector <string> b){
		int n=a.size(),m=b.size(),i,f=0,t;string s,s1;vector <string> out;
		for(i=0;i<n;i++){
			istringstream sin(a[i]);sin>>t>>s>>na[i];de[na[i]]=i;
			if(s=="cups") hi[i]=48*t;if(s=="Tbsp") hi[i]=3*t;if(s=="tsp") hi[i]=t;
		}
		for(i=0;i<m;i++){
			istringstream sin(b[i]);sin>>t>>s>>s1;
			if(s=="cups") im[de[s1]]=48*t;if(s=="Tbsp") im[de[s1]]=3*t;if(s=="tsp") im[de[s1]]=t;
		}
		for(i=0;i<n;i++){if(im[i]>hi[i]) f=1;}
		if(f==0){
			for(i=0;i<n;i++){
				if(hi[i]-im[i]>0) out.pb(cal(hi[i]-im[i])+na[i]);
			}
			return out;
		}
		int gc=hi[0],ba=0;for(i=1;i<n;i++) gc=gcd(gc,hi[i]);for(i=0;i<n;i++) hi2[i]=hi[i]/gc;
		for(i=0;i<n;i++) ba>?=(im[i]-1)/hi2[i]+1;
		for(i=0;i<n;i++){
			if(hi2[i]*ba-im[i]>0) out.pb(cal(hi2[i]*ba-im[i])+na[i]);
		}
		return out;
	}
};
