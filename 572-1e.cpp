//SRM572DIV1-250 NewArenaPassword
#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
bool sumi[58];int num[36];
struct unionf{
	vector <int> data;
	unionf(int size):data(size,-1){}
	bool unions(int x,int y){
		x=root(x);y=root(y);
		if(x!=y){
			if(data[y]<data[x]){int d=x;x=y;y=d;}
			data[x]+=data[y];data[y]=x;
		}
		return x!=y;
	}
	bool finds(int x,int y){
		return root(x)==root(y);
	}
	int root(int x){
		return data[x]<0?x:data[x]=root(data[x]);
	}
	int find(int x){
		return -data[x];
	}
};
class NewArenaPassword{
	public:
	int minChange(string a,int b){
		//memset(gr,false,sizeof(gr));
		int n=a.size(),out=0;unionf uni(n);
		rep(i,b) uni.unions(i,n-b+i);
		memset(sumi,false,sizeof(sumi));
		rep(i,n){
			if(sumi[i]) continue;
			memset(num,0,sizeof(num));
			int t=0,ma=0;
			rep(j,n){
				if(uni.finds(i,j)){
					t++;num[(a[j]-'a')]++;sumi[j]=true;
				}
			}
			rep(j,26) ma=max(ma,num[j]);
			out+=t-ma;
		}
		return out;
	}
};
