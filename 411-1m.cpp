//SRM411DIV1-500 HoleCakeCuts

#include<stdio.h>
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
#include<list>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
using namespace std;

int kei(int lx,int hx,int ly,int hy,int b){
	if(lx>=-b && hx<=b && ly>=-b && hy<=b) return 0;
	if(lx>=-b && hx<=b && ly<-b && hy>b) return 2;
	if(lx<-b && hx>b && ly>=-b && hy<=b) return 2;
	return 1;
}

#define All(s) s.begin(),s.end()
class HoleCakeCuts{
	public:
	int HoleCakeCuts::cutTheCake(int a,int b,vector <int> x,vector <int> y){
		int i,j,out=0;
		x.push_back(a);x.push_back(-a);y.push_back(a);y.push_back(-a);
		sort(All(x));sort(All(y));
		for(i=1;i<x.size();i++) for(j=1;j<y.size();j++) out+=kei(x[i-1],x[i],y[j-1],y[j],b);
		return out;
	}
};

//•Ê‰ð

#include<stdio.h>
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
#include<list>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
using namespace std;

#define All(s) s.begin(),s.end()
class HoleCakeCuts{
	public:
	int HoleCakeCuts::cutTheCake(int a,int b,vector <int> x,vector <int> y){
		int i,k=0,l=0,n=(x.size()+1)*(y.size()+1);
		for(i=0;i<x.size();i++) if(x[i]>=-b && x[i]<=b) k++;
		for(i=0;i<y.size();i++) if(y[i]>=-b && y[i]<=b) l++;
		if(k==0 && l==0) return n;
		if(k==0) return n+l-1;if(l==0) n+k-1;return n-(l-1)*(k-1);
	}
};
