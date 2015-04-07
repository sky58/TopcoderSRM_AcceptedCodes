//SRM307DIV1-500 TrainRobber
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
priority_queue<pint> qu;
lint nex(void){
	pint q=qu.top();qu.pop();qu.push(mp(q.fi-q.se,q.se));return -q.fi;
}
class TrainRobber{
	public:
	double TrainRobber::finalPosition(int l,int car,vector <string> a,vector <string> b,int ts,int rs,int br){
		int i;vector <int> x,y;lint now=0;//double l2=1.0*l*(rs+ts)/rs,now=0.0;cout<<l2<<endl;
		for(i=0;i<a.size();i++){istringstream sin(a[i]);int t;while(sin>>t) x.pb(t);}
		for(i=0;i<b.size();i++){istringstream sin(b[i]);int t;while(sin>>t) y.pb(t);}
		for(i=0;i<x.size();i++) qu.push(mp(-x[i],y[i]));
		for(i=0;i<br;i++){
			lint next=nex();lint t=((next-now)*rs)/((lint)l*(rs+ts));
			if(t>=car) return 1.0*l*(rs+ts)/rs*car+now;car-=t;now=next;
		}
		return now;
	}
};
