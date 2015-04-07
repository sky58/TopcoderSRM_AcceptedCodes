//SRM422DIV1-500 CavePassage
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
typedef pair<int,int> pint;
#define mp make_pair
#define se second
#define fi first
#define pb push_back
struct dijk{
	vector <vector <pint> > ed;
	dijk (int n){
		int i;vector <pint> e;
		for(i=0;i<n;i++) ed.push_back(e);
	}
	void added(int a,int b,int c){
		ed[a].push_back(mp(-c,b));
	}
	int dist(int a,int b){
		int i;vector <int> ten,zan;
		for(i=0;i<ed.size();i++){ten.push_back(1);zan.pb(-1000000000);}
		priority_queue<pint> q;q.push(mp(0,a));
		while(!q.empty() && ten[b]==1){
			pint e=q.top();q.pop();
//			cout<<e.fi<<' '<<e.se<<'\n';
			if(ten[e.se]!=1) continue;
			ten[e.se]=e.fi;
			for(i=0;i<ed[e.se].size();i++){
				if(zan[ed[e.se][i].se]<e.fi+ed[e.se][i].fi){
					q.push(mp(e.fi+ed[e.se][i].fi,ed[e.se][i].se));
					zan[ed[e.se][i].se]=e.fi+ed[e.se][i].fi;
				}
			}
		}
		return -ten[b];
	}
};
int bitc(int a){return a==0?0:a%2+bitc(a/2);}
class CavePassage{
	public:
	int CavePassage::minimalTime(vector <int> a,vector <int> b,vector <string> c,int d){
		int n=a.size(),i,j,k;int zika[60000];
		
		dijk ds(17000);
		for(i=1;i<(1<<n);i++){
			int he=0,zi=0;
			for(j=0;j<n;j++){
				if(i&(1<<j)){
					zi=max(zi,b[j]);he+=a[j];
					int fl=1;for(k=0;k<n;k++) if((i&(1<<k)) && j!=k && c[j][k]=='Y') fl=0;
					if(bitc(i)>1 && fl==1) zika[i]=-1;
				}
			}
			if(he>d) zika[i]=-1;if(zika[i]!=-1) zika[i]=zi;
//			cout<<i<<' '<<zika[i]<<'\n';
		}
		for(i=1;i<(1<<n);i++){
			vector <int> f;
			for(j=0;j<n;j++) if(i&(1<<j)) f.push_back(j);
			for(j=1;j<(1<<(f.size()));j++){
				int t=0;
				for(k=0;k<f.size();k++) if(j&(1<<k)) t+=(1<<f[k]);
//				cout<<i<<' '<<j<<' '<<t<<'\n';
				if(zika[t]!=-1){
					ds.added(i,i-t+(1<<n),zika[t]);
//					cout<<i<<' '<<i-t+(1<<n)<<' '<<zika[t]<<'\n';
					ds.added((1<<(n+1))-i-1,(1<<n)-i+t-1,zika[t]);
//					cout<<(1<<(n+1))-i-1<<' '<<(1<<n)-i+t-1<<' '<<zika[t]<<'\n';
				}
			}
		}
		return ds.dist((1<<n)-1,(1<<n));
	}
};
