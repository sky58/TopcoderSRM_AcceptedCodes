//SRM438DIV1-500(DIV2-1000) EndlessStringMachine
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
#include<queue>
#include<deque>
using namespace std;
#define lint long long
lint inf=1000000;
string a,b;
int m,n;
vector <lint> zyo;
char dfs(int k,int l){
	int i;
	if(k==0) return a[l];
	for(i=0;i<n;i++){
		if(b[i]=='$'){
			if(zyo[k-1]>l) return dfs(k-1,l);
			l-=zyo[k-1];
		}
		else{
			if(l==0) return b[i];l--;
		}
	}
	return '-';
}
char kei(int k,int l){
	int i;
//	if(zyo[k]<(lint)l) return '-';
	for(i=0;i<zyo.size();i++){
		if(zyo[i]>(lint)l) break;
	}
	return dfs(min(k,i),l);
}
class EndlessStringMachine{
	public:
	string EndlessStringMachine::getFragment(string A,string B,int s,int st,int go){
		a=A;b=B;m=a.size();n=b.size();int i,dol=0;string out;inf*=inf;
		
		for(i=0;i<n;i++) if(b[i]=='$') dol++;
		if(dol==1){
			for(i=st-1;i<go;i++){
				if(i<m) out+=a[i];
				else if((lint)(i-m)<(lint)(n-1)*s) out+=b[(i-m)%(n-1)+1];
				else out+='-';
			}
			return out;
		}
		zyo.push_back(m);
		for(i=0;i<50;i++){
			zyo.push_back(zyo[i]*dol+(n-dol));
			if(zyo[i+1]>inf) break;
		}
		for(i=st-1;i<go;i++) out+=kei(s,i);
		return out;
	}
};
