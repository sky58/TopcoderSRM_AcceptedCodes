//SRM479DIV1-500 TheAirTripDivOne
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
typedef pair<lint,lint> pint;
vector <vector <int> > gr;
int lim,n,m;lint inf=1100000000;
lint dp[500];priority_queue<pint> qu;
bool ch(int ka){
	int i,j;
	for(i=0;i<500;i++) dp[i]=inf;dp[1]=0;
	for(i=0;i<n+10;i++) for(j=0;j<m;j++){
		int a=gr[j][0],b=gr[j][1];lint f=gr[j][2],t=gr[j][3],p=gr[j][4],x=dp[a],y;
		if(a!=1) x+=ka;if(x<=f) y=f+t;else y=((x-f-1)/p+1)*p+t+f;dp[b]<?=y;
//		cout<<b<<' '<<dp[b]<<endl;
	}
	if((int)dp[n]<=lim) return true;return false;
}
class TheAirTripDivOne{
  public:
  int TheAirTripDivOne::find(int N,vector <string> str,int Lim){
    int hi=1000000100,lo=0,i,a,b,f,t,p,u=0;
    string st,s;for(i=0;i<str.size();i++) st+=str[i];istringstream sin(st);
    vector <string> st2;
    char x,y,z,w;lim=Lim;n=N;
    while(u<=st.size()){
      sin>>s;u+=s.size()+1;st2.pb(s);
    }
    m=st2.size();
    for(i=0;i<m;i++){
      istringstream sin2(st2[i]);
      sin2>>a>>x>>b>>y>>f>>z>>t>>w>>p;
      vector <int> c;c.pb(a);c.pb(b);c.pb(f);c.pb(t);c.pb(p);gr.pb(c);
    }
    if(!ch(1)) return -1;
   while(hi>lo){
//      cout<<hi<<' '<<lo<<endl;
      int me=(hi+lo+1)/2;if(ch(me)) lo=me;else hi=me-1;
    }
    if(hi<=0) return -1;return hi;
  }
};
